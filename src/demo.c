#include "demo.h"

u64 dm_GetLibcBase()
{
    FILE *fp;
    u64 addr = 0;
    char line[256];

    fp = fopen("/proc/self/maps", "r");
    if (fp == NULL)
    {
        perror("无法打开 [/proc/self/maps] 文件");
        return addr;
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "libc") && strstr(line, "r-xp"))
        {
            sscanf(line, "%llx", &addr);
            break;
        }
    }

    fclose(fp);

    if (addr == 0)
        perror("获取libc基地址失败");

    return addr;
}