/**
 * demo
 */
#ifndef DEMO_H_
#define DEMO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

#define GET_ADDR_VALUE(addr) ((u64)(*(u64 *)(addr)))   // 获取地址的值
#define GET_ADDR_VALUE32(addr) ((u32)(*(u32 *)(addr))) // 获取地址的值

#define PUT_VALUE(value) printf("%p", (void *)(value))   // 打印值
#define PUT_VALUE32(value) printf("%p", (void *)(value)) // 打印值

#define PUT_ADDR_VALUE(value) printf("%p", *(void **)(value))   // 打印地址中的值
#define PUT_ADDR_VALUE32(value) printf("%p", *(void **)(value)) // 打印地址中的值

#define SET_ADDR_VALUE(addr, value) (*(u64 *)(addr) = (u64)(value))   // 设置地址的值
#define SET_ADDR_VALUE32(addr, value) (*(u32 *)(addr) = (u32)(value)) // 设置地址的值

#define SET_ADDR_OFFSET_VALUE(addr, offset, value) (*(u64 *)(((u8 *)(addr)) + (offset)) = (u64)(value))   // 设置带便宜的地址中的值
#define SET_ADDR_OFFSET_VALUE32(addr, offset, value) (*(u32 *)(((u8 *)(addr)) + (offset)) = (u32)(value)) // 设置带便宜的地址中的值

#define GET_VALUE_POS(value, pos) ((u8)(((value) >> (pos)) & 0xFF)) // 获取值的第pos个字节, 小端序

#define ENC_VALUE(addr, target) ((((u64)(addr)) >> 12) ^ ((u64)(target))) // 加密地址

/**
 * \brief 获取libc基地址
 */
u64 GetLibcBase();

#endif // DEMO_H_
