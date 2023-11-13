#include <stddef.h>
#include <stdint.h>
#include "ANSI_colors.h"

uint8_t bg_color(uint8_t COLOR) {
  return COLOR << 4;
} 

uint8_t color(uint8_t FG, uint8_t BG) {
  return FG | bg_color(BG);
}

uint16_t pchar(uint16_t c, uint8_t color) {
  return c | color << 8; 
}
