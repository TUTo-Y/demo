/**
 * demo
 */
#ifndef DEMO_H_
#define DEMO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "demo_error.h"
#include "demo_web.h"

/**
 * 基础数据类型定义
 */
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef signed long long s64;
typedef signed int s32;
typedef signed short s16;
typedef signed char s8;

/**
 * 基础运算赋值
 */
/* 偏移操作 */
#define GET_OFFSET(offset) ((s64)(offset))   // 获取偏移
#define GET_OFFSET32(offset) ((s32)(offset)) // 获取偏移

/* 值操作 */
#define GET_VALUE(value) ((u64)(value))   // 获取值
#define GET_VALUE32(value) ((u32)(value)) // 获取值

#define GET_VALUE_OFFSET(value, offset) GET_VALUE(GET_VALUE(value) + GET_OFFSET(offset))         // 获取带偏移的值
#define GET_VALUE_OFFSET32(value, offset) GET_VALUE32(GET_VALUE32(value) + GET_OFFSET32(offset)) // 获取带偏移的值

#define SET_VALUE(value, data) ((value) = GET_VALUE(data))     // 设置值
#define SET_VALUE32(value, data) ((value) = GET_VALUE32(data)) // 设置值

#define SET_VALUE_OFFSET(value, offset, data) SET_VALUE(value, GET_VALUE_OFFSET(data, offset))       // 设置带偏移的值
#define SET_VALUE_OFFSET32(value, offset, data) SET_VALUE32(value, GET_VALUE_OFFSET32(data, offset)) // 设置带偏移的值

#define PUT_VALUE(str, value) printf("%s : 0x%llx\n", str, GET_VALUE(value))   // 打印值
#define PUT_VALUE32(str, value) printf("%s : 0x%x\n", str, GET_VALUE32(value)) // 打印值

/* 地址操作 */
#define GET_ADDR_VALUE(addr) (*(u64 *)(addr))   // 获取地址的值
#define GET_ADDR_VALUE32(addr) (*(u32 *)(addr)) // 获取地址的值

#define GET_ADDR_OFFSET_VALUE(addr, offset_addr) GET_ADDR_VALUE(GET_VALUE_OFFSET(addr, offset_addr))       // 获取带偏移的地址的值
#define GET_ADDR_OFFSET_VALUE32(addr, offset_addr) GET_ADDR_VALUE32(GET_VALUE_OFFSET32(addr, offset_addr)) // 获取带偏移的地址的值

#define GET_ADDR_VALUE_OFFSET(addr, offset_value) GET_VALUE_OFFSET(GET_ADDR_VALUE(addr), offset_value)       // 获取地址的值带偏移
#define GET_ADDR_VALUE_OFFSET32(addr, offset_value) GET_VALUE_OFFSET32(GET_ADDR_VALUE32(addr), offset_value) // 获取地址的值带偏移

#define GET_ADDR_OFFSET_VALUE_OFFSET(addr, offset_addr, offset_value) GET_VALUE_OFFSET(GET_ADDR_VALUE(GET_VALUE_OFFSET(addr, offset_addr)), offset_value)         // 获取带偏移的地址的值带偏移
#define GET_ADDR_OFFSET_VALUE_OFFSET32(addr, offset_addr, offset_value) GET_VALUE_OFFSET32(GET_ADDR_VALUE32(GET_VALUE_OFFSET32(addr, offset_addr)), offset_value) // 获取带偏移的地址的值带偏移

#define SET_ADDR_VALUE(addr, value) SET_VALUE(GET_ADDR_VALUE(addr), value)       // 设置地址的值
#define SET_ADDR_VALUE32(addr, value) SET_VALUE32(GET_ADDR_VALUE32(addr), value) // 设置地址的值

#define SET_ADDR_OFFSET_VALUE(addr, offset_addr, value) SET_VALUE(GET_ADDR_OFFSET_VALUE(addr, offset_addr), value)       // 设置带偏移的地址的值
#define SET_ADDR_OFFSET_VALUE32(addr, offset_addr, value) SET_VALUE32(GET_ADDR_OFFSET_VALUE32(addr, offset_addr), value) // 设置带偏移的地址的值

#define SET_ADDR_VALUE_OFFSET(addr, value, offset_value) SET_VALUE_OFFSET(GET_ADDR_VALUE(addr), offset_value, value)       // 设置地址的值带偏移
#define SET_ADDR_VALUE_OFFSET32(addr, value, offset_value) SET_VALUE_OFFSET32(GET_ADDR_VALUE32(addr), offset_value, value) // 设置地址的值带偏移

#define SET_ADDR_OFFSET_VALUE_OFFSET(addr, offset_addr, value, offset_value) SET_VALUE_OFFSET(GET_ADDR_OFFSET_VALUE(addr, offset_addr), offset_value, value)       // 设置带偏移的地址的值带偏移
#define SET_ADDR_OFFSET_VALUE_OFFSET32(addr, offset_addr, value, offset_value) SET_VALUE_OFFSET32(GET_ADDR_OFFSET_VALUE32(addr, offset_addr), offset_value, value) // 设置带偏移的地址的值带偏移

#define PUT_ADDR_VALUE(str, addr) printf("%s : 0x%llx\n", str, GET_VALUE(GET_ADDR_VALUE(addr)))     // 打印地址中的值
#define PUT_ADDR_VALUE32(str, addr) printf("%s : 0x%x\n", str, GET_VALUE32(GET_ADDR_VALUE32(addr))) // 打印地址中的值

/**
 * 特殊运算
 */
// 循环右移
#define ROR(x, n) ({                                      \
    u64 _x = (x);                                         \
    u64 _n = (n);                                         \
    __asm__("ror %1, %0" : "=r"(_x) : "cI"(_n), "0"(_x)); \
    _x;                                                   \
})

// 循环左移
#define ROL(x, n) ({                                      \
    u64 _x = (x);                                         \
    u64 _n = (n);                                         \
    __asm__("rol %1, %0" : "=r"(_x) : "cI"(_n), "0"(_x)); \
    _x;                                                   \
})

/**
 * libc加密运算
 */
#define PROTECT_FD(key, value) ((((u64)(key)) >> 12) ^ ((u64)(value))) // ptmalloc中对fd的加密
#define ENC_FD(ptr) PROTECT_FD(&(ptr), ptr)                            // ptmalloc中对fd的解密

#define ENC_PTR1(ptr, pointer_guard, n) (ROL((u64)(ptr) ^ (u64)(pointer_guard), n)) // ptmalloc中对指针的加密
#define DEC_PTR1(ptr, pointer_guard, n) (ROR((u64)(ptr), n) ^ (u64)(pointer_guard)) // ptmalloc中对指针的加密

#define ENC_PTR2(ptr, pointer_guard) ENC_PTR1(ptr, pointer_guard, 0x11) // ptmalloc中对指针的加密
#define DEC_PTR2(ptr, pointer_guard) DEC_PTR1(ptr, pointer_guard, 0x11) // ptmalloc中对指针的加密

/**
 * 其他宏
 */
#define MALLOC(size) (u64) malloc((u64)(size))                                                                                      // 申请内存
#define FREE(ptr) free((void *)(ptr))                                                                                               // 释放内存
#define LINE putchar('\n');                                                                                                         // 换行
#define BINSH 0x68732f6e69622f                                                                                                      // /bin/sh
#define SH 0x3024                                                                                                                   // $0
#define PUT_STRUCT(s, name) printf("%s : 偏移:0x%llX  大小:0x%llX\n", #name, (u64)(&((s *)0)->name), (u64)(sizeof(((s *)0)->name))) // 输出结构体成员的偏移和大小

/**
 * \brief 获取libc基地址
 */
u64 dm_GetLibcBase();

/**
 * \brief 初始化标准输入输出错误
 */
void dm_InitStd();

#endif // DEMO_H_
