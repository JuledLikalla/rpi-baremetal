#include "led_display.h"

gpio  zero[6] = { GPIO0, GPIO1, GPIO5, GPIO6, GPIO12, GPIO13 };
gpio   one[2] = { GPIO1, GPIO5 };
gpio   two[5] = { GPIO0, GPIO1, GPIO6, GPIO12, GPIO19 };
gpio three[5] = { GPIO0, GPIO1, GPIO5, GPIO6, GPIO19 };
gpio  four[4] = { GPIO1, GPIO5, GPIO13, GPIO19 };
gpio  five[5] = { GPIO0, GPIO5, GPIO6, GPIO13, GPIO19 };
gpio   six[6] = { GPIO0, GPIO5, GPIO6, GPIO12, GPIO13, GPIO19 };
gpio seven[3] = { GPIO0, GPIO1, GPIO5 };
gpio eight[7] = { GPIO0, GPIO1, GPIO5, GPIO6, GPIO12, GPIO13, GPIO19};
gpio  nine[6] = { GPIO0, GPIO1, GPIO5, GPIO6, GPIO13, GPIO19};

gpio *table[] = { zero, one, two, three, four, five, six, seven, eight, nine }; 
uint32_t nrOfDigits[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }; 
iocfg types[7] = { OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT};

void init_display(void) {
  init_gpios(eight, types, nrOfDigits[8]);
}

void printNr(uint32_t Nr) {
  clear_pins(eight, nrOfDigits[8]);
  set_pins(table[Nr], nrOfDigits[Nr]);
}