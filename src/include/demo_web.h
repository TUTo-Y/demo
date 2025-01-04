/**
 * demo的网络接口
 */
#ifndef DEMO_WEB_H
#define DEMO_WEB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/select.h>

#include "demo_error.h"
#include "demo_mem.h"

typedef struct
{
    dm_Error error; // 错误信息

    int socket; // 套接字
    fd_set fds; // 使用select模型
} dm_Socket;

/**
 * \brief 初始化网络
 */
void dm_SocketInit(dm_Socket *s);

/**
 * \brief 连接到网络
 */
bool dm_SocketConnect(dm_Socket *s, const char *host, int port);

/**
 * \brief 读取数据
 * \param s 网络
 * \param size 读取的大小, 0表示发送多少读取多少
 * \param mem 读取的数据
 */
bool dm_SocketRecv(dm_Socket *s, size_t size, dm_Mem *mem, struct timeval *timeout);

/**
 * 关闭网络
 */
void dm_SocketClose(dm_Socket *s);

#endif // DEMO_WEB_H