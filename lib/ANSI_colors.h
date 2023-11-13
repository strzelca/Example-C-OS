#ifndef ANSI_COLORS
#define ANSI_COLORS

#include <stdint.h>

#define BLACK   0
#define BLUE    1
#define GREEN   2
#define CYAN    3
#define RED     4
#define MAGENTA 5
#define BROWN   6
#define WHITE   15


#define LIGHT_GREY    7
#define DARK_GREY     8
#define LIGHT_BLUE    9
#define LIGHT_GREEN   10
#define LIGHT_CYAN    11
#define LIGHT_RED     12
#define LIGHT_MAGENTA 13
#define LIGHT_BROWN   14


uint8_t bg_color(uint8_t COLOR);
uint8_t color(uint8_t FG, uint8_t BG);
uint16_t pchar(uint16_t c, uint8_t color);

#endif // !ANSI_COLORS

