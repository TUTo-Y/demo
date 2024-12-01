#include "demo_error.h"

void dm_InitError(dm_Error *error)
{
    if (!error)
        return;

    error->message = NULL;
    error->is_error = false;
}

char *dm_SetErrorMsg(dm_Error *error, const char *message)
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

char *dm_SetErrorMsg2(dm_Error *error, const char *message)
{
    if (!error)
        return NULL;
    if (!message)
        return NULL;

    char *err_message = strerror(errno);

    // 分配消息内存
    error->message = (char *)realloc(error->message, strlen(message) + strlen(err_message) + 5);
    if (!error->message)
        return NULL;

    // 复制消息内容
    strcpy(error->message, message);
    strcat(error->message, " : ");
    strcat(error->message, err_message);

    // 设置错误标志
    error->is_error = true;

    // 返回消息内容
    return error->message;
}

char *dm_GetErrorMsg(const dm_Error *error)
{
    if (!error)
        return NULL;

    // 当错误消息被设置时返回错误信息
    if (error->is_error == true)
        return error->message;

    return NULL;
}

bool dm_HasError(const dm_Error *error)
{
    if (!error)
        return false;
    
    return error->is_error;
}

void dm_ClearError(dm_Error *error)
{
    if (!error)
        return;

    // 设置错误标志
    error->is_error = false;
}

void dm_PrintError(const dm_Error *error)
{
    if (!error)
        return;

    // 当错误消息被设置时打印错误信息
    if (error->is_error == true)
        fprintf(stderr, "%s%s%s\n", _RED, error->message, RESET);
}

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