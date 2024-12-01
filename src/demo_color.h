/**
 * @file demo_color.h
 * @brief 输出字体颜色
 */
#ifndef COLOR_H_
#define COLOR_H_

// 输出字体颜色
#define RESET   "\x1B[0m"   // 重置为默认颜色
#define _BLK    "\x1B[30m"  // 黑色
#define _RED    "\x1B[31m"  // 红色
#define _GRN    "\x1B[32m"  // 绿色
#define _YEL    "\x1B[33m"  // 黄色
#define _BLU    "\x1B[34m"  // 蓝色
#define _MAG    "\x1B[35m"  // 洋红色
#define _CYN    "\x1B[36m"  // 青色
#define _WHT    "\x1B[37m"  // 白色
#define _BBLK   "\x1B[90m"  // 亮黑色
#define _BRED   "\x1B[91m"  // 亮红色
#define _BGRN   "\x1B[92m"  // 亮绿色
#define _BYEL   "\x1B[93m"  // 亮黄色
#define _BBLU   "\x1B[94m"  // 亮蓝色
#define _BMAG   "\x1B[95m"  // 亮洋红色
#define _BCYN   "\x1B[96m"  // 亮青色
#define _BWHT   "\x1B[97m"  // 亮白色

#define BLK(str)    _BLK str RESET    // 黑色
#define RED(str)    _RED str RESET    // 红色
#define GRN(str)    _GRN str RESET    // 绿色
#define YEL(str)    _YEL str RESET    // 黄色
#define BLU(str)    _BLU str RESET    // 蓝色
#define MAG(str)    _MAG str RESET    // 洋红色
#define CYN(str)    _CYN str RESET    // 青色
#define WHT(str)    _WHT str RESET    // 白色
#define BBLK(str)   _BBLK str RESET    // 亮黑色
#define BRED(str)   _BRED str RESET    // 亮红色
#define BGRN(str)   _BGRN str RESET    // 亮绿色
#define BYEL(str)   _BYEL str RESET    // 亮黄色
#define BBLU(str)   _BBLU str RESET    // 亮蓝色
#define BMAG(str)   _BMAG str RESET    // 亮洋红色
#define BCYN(str)   _BCYN str RESET    // 亮青色
#define BWHT(str)   _BWHT str RESET    // 亮白色

#endif // COLOR_H_