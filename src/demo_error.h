#ifndef DEMO_ERROR_H
#define DEMO_ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char *message;
    bool is_error;
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
char *dm_SetError(dm_Error *error, const char *message);

/**
 * \brief 清除错误信息
 * \param error 错误信息
 */
void dm_ClearError(dm_Error *error);

/**
 * \brief 获取错误信息内容
 * \param error 错误信息
 * \return 返回错误信息内容
 */
char *dm_PrintError(const dm_Error *error);

/**
 * \brief 释放错误信息
 * \param error 错误信息
 * \return 返回错误信息
 */
void dm_FreeError(dm_Error *error);

#endif // DEMO_ERROR_H