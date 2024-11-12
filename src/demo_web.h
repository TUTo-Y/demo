/**
 * demo的网络接口
 */
#ifndef DEMO_WEB_H
#define DEMO_WEB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>

#include "demo_error.h"

typedef struct
{
    dm_Error error; // 错误信息

    int socket;
} dm_Socket;

/**
 * 初始化网络
 */
bool dm_SocketInit(dm_Socket *socket, const char *ip, int port);

/**
 * 关闭网络
 */
bool dm_SocketClose(dm_Socket *socket);

#endif // DEMO_WEB_H