#include "demo_web.h"

void dm_SocketInit(dm_Socket *s)
{
    if (s == NULL)
        return;

    // 重置
    memset(s, 0, sizeof(dm_Socket));

    // 初始化错误
    dm_InitError(&s->error);
}

bool dm_SocketConnect(dm_Socket *s, const char *host, int port)
{
    struct hostent *he;
    
    // 初始化socket
    dm_SocketInit(s);

    // 解析主机名或IP地址
    if ((he = gethostbyname(host)) == NULL)
    {
        dm_SetErrorMsg2(&s->error, "解析主机名错误");
        return false;
    }

    // 创建套接字
    s->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (s->socket == -1)
    {
        dm_SetErrorMsg2(&s->error, "创建socket错误");
        return false;
    }

    // 设置服务器地址
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *)he->h_addr_list[0]);
    memset(&(addr.sin_zero), 0, 8);

    // 连接到服务器
    if (connect(s->socket, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        dm_SetErrorMsg2(&s->error, "连接到服务器失败");
        close(s->socket);
        return false;
    }

    // 初始化select模型
    FD_ZERO(&s->fds);
    FD_SET(s->socket, &s->fds);

    return true;
}

bool dm_SocketRecv(dm_Socket *s, size_t size, dm_Mem *mem, struct timeval *timeout)
{
    if (s == NULL || mem == NULL)
        return false;

    // 初始化存储空间
    *mem = dm_MemCreate(0);

    // 监听读事件数据
    fd_set readfds = s->fds;

    while (true)
    {
        int ret = select(s->socket + 1, &readfds, NULL, NULL, timeout);
        if (ret == 0) // 超时
        {
            dm_SetErrorMsg2(&s->error, "select超时");
            return false;
        }
        else if (ret < 0) // 错误
        {
            dm_SetErrorMsg2(&s->error, "select错误");
            return false;
        }
        else if (FD_ISSET(s->socket, &readfds)) // 有数据
        {
            // 获取缓冲区内数据大小
            size_t len = 0;
            ioctl(s->socket, FIONREAD, &len);

            // 检查连接是否断开
            if (len == 0)
            {
                dm_SetErrorMsg2(&s->error, "连接断开");
                return false;
            }

            // 如果给了size, 则需要确定实际读取大小
            if (size != 0)
            {
                // 需要读取的大小不能超过size
                len = size - DM_MEM_SIZE(*mem) > len ? len : size - DM_MEM_SIZE(*mem);
            }

            // 重新分配内存并读取数据
            size_t old_size = DM_MEM_SIZE(*mem);
            dm_MemRealloc(mem, old_size + len);
            ssize_t r = recv(s->socket, DM_MEM_DATA(*mem) + old_size, len, 0);
            if (r == -1)
            {
                dm_SetErrorMsg2(&s->error, "读取数据错误");
                return false;
            }
            else if (r == 0)
            {
                dm_SetErrorMsg2(&s->error, "连接断开");
                return false;
            }

            // 检查是否需要返回
            if (DM_MEM_SIZE(*mem) >= size)
                return true;
        }
    }

    return true;
}

void dm_SocketClose(dm_Socket *s)
{
    if (s == NULL)
        return;

    // 清空错误
    dm_FreeError(&s->error);

    // 关闭套接字
    close(s->socket);
    s->socket = 0;

    // 重置数据
    memset(s, 0, sizeof(dm_Socket));
}