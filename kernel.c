#include <stdint.h>
#include <stddef.h>
#include "lib/print.h"

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();
  
  const char* text = "CIAOOO!\nCome stai?\n";
  
  print(text);

  print_rainbow("Un programma che funziona per miracolo!\nEVVIVA CHE FUNZIONA\n")
;

  print_rainbow("19 dollar fortnite card, WHO WANT IT???\n");
}
