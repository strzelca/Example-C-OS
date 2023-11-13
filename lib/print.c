#include <stdint.h>
#include <stddef.h>
#include "string.h"
#include "print.h"
#include "ANSI_colors.h"

size_t y;
size_t x;
uint16_t* fb;

void terminal_initialize(void) 
{
	y = 0;
	x = 0;
	fb = (uint16_t*) FRAMEBUFFER;
	for (size_t i = 0; i < VGA_HEIGHT; i++) {
		for (size_t j = 0; j < VGA_WIDTH; j++) {
			const size_t index = i * VGA_WIDTH + j;
			fb[index] = (' ' |  (15 | 0 << 4) << 8 );
		}
	}
}

void print(const char* string){ 

  for(size_t i = 0; i < strlen(string); i++) {
    const size_t index = y*VGA_WIDTH+x;
    switch(string[i]) {
      case '\n':
        ++y;
        x=0;
        break;
      default:
        fb[index] = pchar(string[i], color(WHITE, BLACK));
        if (++x == VGA_WIDTH) {
		      x = 0;
		    if (++y == VGA_HEIGHT) 
          y = 0;
	      }

        break;
    }  
  }
}

void print_rainbow(const char* string){ 

  for(size_t i = 0; i < strlen(string); i++) {
    const size_t index = y*VGA_WIDTH+x;
    switch(string[i]) {
      case '\n':
        ++y;
        x=0;
        break;
      default:
        fb[index] = pchar(string[i], color((i % WHITE /2+1), BLACK));
        if (++x == VGA_WIDTH) {
		      x = 0;
		    if (++y == VGA_HEIGHT) 
          y = 0;
	      }

        break;
    }  
  }
}
