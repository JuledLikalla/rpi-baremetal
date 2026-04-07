#include "sys_common.h"

void delay(int32_t count) {
    while (count--) {
        __asm__ volatile("nop");
    }
}
