#include "demo_error.h"

/**
 * \brief 初始化错误信息
 * \param error 错误信息
 */
void dm_InitError(dm_Error *error)
{
    if (!error)
        return;
    error->message = NULL;
    error->is_error = false;
}

/**
 * \brief 设置错误信息
 * \param error 错误信息
 * \param message 错误信息内容
 * \return 返回错误信息内容
 */
char *dm_SetError(dm_Error *error, const char *message)
{
    if (!error)
        return NULL;
    if (!message)
        return NULL;

    // 分配消息内存
    error->message = (char *)realloc(error->message, strlen(message) + 1);
    if (!error->message)
        return NULL;

    // 复制消息内容
    strcpy(error->message, message);

    // 设置错误标志
    error->is_error = true;
    
    // 返回消息内容
    return error->message;
}

/**
 * \brief 清除错误信息
 * \param error 错误信息
 */
void dm_ClearError(dm_Error *error)
{
    if (!error)
        return;

    // 设置错误标志
    error->is_error = false;
}

/**
 * \brief 获取错误信息内容
 * \param error 错误信息
 * \return 返回错误信息内容
 */
char *dm_PrintError(const dm_Error *error)
{
    if (!error)
        return NULL;

    // 当error->is_error为真时返回错误信息
    if (error->is_error == true)
        return error->message;

    return NULL;
}

/**
 * \brief 释放错误信息
 * \param error 错误信息
 * \return 返回错误信息
 */
void dm_FreeError(dm_Error *error)
{
    if (!error)
        return;

    // 释放消息内存
    if (error->message)
        free(error->message);

    // 初始化错误信息
    dm_InitError(error);
}