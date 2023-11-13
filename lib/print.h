#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdint.h>
#include <stddef.h>

#define FRAMEBUFFER 0xB8000
#define VGA_WIDTH  80
#define VGA_HEIGHT 25

void print(const char* string);
void print_rainbow(const char* string);
void terminal_initialize();

#endif
