#ifndef DEMO_ERROR_H
#define DEMO_ERROR_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "demo_color.h"

typedef struct
{
    char *message; // 错误信息内容
    bool is_error; // 当前错误是否被设置
} dm_Error;

/**
 * \brief 初始化错误信息
 * \param error 错误信息
 */
void dm_InitError(dm_Error *error);

/**
 * \brief 设置错误信息
 * \param error 错误信息
 * \param message 错误信息内容
 * \return 返回错误信息内容
 */
char *dm_SetErrorMsg(dm_Error *error, const char *message);

/**
 * \brief 设置错误信息（使用strerror）
 * \param error 错误信息
 * \param message 错误信息内容
 * \return 返回错误信息内容
 */
char *dm_SetErrorMsg2(dm_Error *error, const char *message);

/**
 * \brief 获取错误信息内容
 * \param error 错误信息
 * \return 返回错误信息内容
 */
char *dm_GetErrorMsg(const dm_Error *error);

/**
 * \brief 检查是否有错误
 * \param error 错误信息
 * \return 返回是否有错误
 */
bool dm_HasError(const dm_Error *error);

/**
 * \brief 清除错误信息
 * \param error 错误信息
 */
void dm_ClearError(dm_Error *error);

/**
 * \brief 打印错误信息
 * \param error 错误信息
 * \return 返回错误信息
 */
void dm_PrintError(const dm_Error *error);

/**
 * \brief 释放错误信息
 * \param error 错误信息
 * \return 返回错误信息
 */
void dm_FreeError(dm_Error *error);

#endif // DEMO_ERROR_H