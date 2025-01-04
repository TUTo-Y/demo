#include <demo.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
    dm_Socket s;
    bool ret;

    if(dm_SocketConnect(&s, "node5.buuoj.cn", 25648) == false)
    {
        dm_PrintError(&s.error);
        return 0;
    }

    dm_Mem mem;
    struct timeval timeout = {3, 0};
    ret = dm_SocketRecv(&s, 19, &mem, &timeout);
    if(ret == false)
    {
        dm_PrintError(&s.error);
        return 0;
    }
    printf("[%ld][%s]\n", DM_MEM_SIZE(mem), DM_MEM_DATA(mem));

    return 0;
}
