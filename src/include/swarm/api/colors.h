#ifndef COLORS_API_FS
#define COLORS_API_FS

#include <base.h>

// number definitions
#define colors_white      1
#define colors_orange     2
#define colors_magenta    4
#define colors_lightBlue  8
#define colors_yellow     16
#define colors_lime       32
#define colors_pink       64
#define colors_gray       128
#define colors_lightGray  256
#define colors_cyan       512
#define colors_purple     1024
#define colors_blue       2048
#define colors_brown      4096
#define colors_green      8192
#define colors_red        16384
#define colors_black      32768

void api_colors_open(lua_State *L);

#endif /* end of include guard: COLORS_API_FS */
