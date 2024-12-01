#ifndef DEMO_MEM_H
#define DEMO_MEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char *data;
    size_t size;
} dm_Mem;

#define DM_MEM_SIZE(mem) ((mem).size)
#define DM_MEM_DATA(mem) ((mem).data)

/**
 * \brief 创建一块内存
 */
dm_Mem dm_MemCreate(size_t size);
dm_Mem dm_MemCreateFromData(const void *data, size_t size);

/**
 * \brief 重新分配内存
 */
void dm_MemRealloc(dm_Mem *mem, size_t size);

/**
 * \brief 追加数据
 */
void dm_MemAppend(dm_Mem *mem, const void *data, size_t size);

/**
 * \brief 从mem追加数据
 */
void dm_MemAppendFromMem(dm_Mem *mem, dm_Mem *data, bool free_data);

/**
 * \brief 释放内存
 */
void dm_MemFree(dm_Mem *mem);

#endif // DEMO_MEM_H