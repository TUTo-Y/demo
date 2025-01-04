#include "demo_mem.h"

dm_Mem dm_MemCreate(size_t size)
{
    return (dm_Mem){(char *)malloc(size), size};
}

dm_Mem dm_MemCreateFromData(const void *data, size_t size)
{
    dm_Mem mem;

    if (data == NULL)
    {
        DM_MEM_INIT(mem);
    }
    else
    {
        mem = dm_MemCreate(size);
        memcpy(DM_MEM_DATA(mem), data, size);
    }

    return mem;
}

dm_Mem dm_MemRealloc(dm_Mem mem, size_t size)
{
    DM_MEM_DATA(mem) = (char *)realloc(DM_MEM_DATA(mem), size);
    DM_MEM_SIZE(mem) = size;
    return mem;
}

dm_Mem dm_MemAppend(dm_Mem mem, const void *data, size_t size)
{
    size_t old_size = DM_MEM_SIZE(mem);
    mem = dm_MemRealloc(mem, old_size + size);
    memcpy(DM_MEM_DATA(mem) + old_size, data, size);

    return mem;
}

dm_Mem dm_MemAppendFromMem(dm_Mem mem, dm_Mem data, bool free_data)
{
    mem = dm_MemAppend(mem, DM_MEM_DATA(data), DM_MEM_SIZE(data));

    if (free_data == true)
        dm_MemFree(data);
}

void dm_MemFree(dm_Mem mem)
{
    free(DM_MEM_DATA(mem));
}
