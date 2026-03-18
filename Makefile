CROSS ?= arm-none-eabi

CFLAGS  = -mcpu=cortex-a7 -marm -mfpu=vfpv3 -mfloat-abi=hard -ffreestanding -nostdlib -nostartfiles -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -nostdlib

all: kernel7.img

boot.o: boot.S
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

kernel7.elf: boot.o main.o linker.ld
	$(CROSS)-gcc $(CFLAGS) boot.o main.o $(LDFLAGS) -o $@

kernel7.img: kernel7.elf
	$(CROSS)-objcopy kernel7.elf -O binary $@

disasm: kernel7.elf
	$(CROSS)-objdump -D kernel7.elf > kernel7.lst

clean:
	rm -f *.o *.elf *.img *.lst