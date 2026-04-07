CROSS ?= arm-none-eabi

CFLAGS   = -std=gnu23 
CFLAGS 	+= -mcpu=cortex-a7
CFLAGS  += -marm 
CFLAGS  += -mfpu=vfpv3 
CFLAGS  += -mfloat-abi=hard 
CFLAGS  += -ffreestanding
CFLAGS  += -nostartfiles 
CFLAGS  += -O2 
CFLAGS  += -Wall 
CFLAGS  += -Wextra
CFLAGS  += -Iinclude

LDFLAGS   = -T linker.ld
LDFLAGS  += -mcpu=cortex-a7
LDFLAGS  += -marm 
LDFLAGS  += -mfpu=vfpv3 
LDFLAGS  += -mfloat-abi=hard 
LDFLAGS  += -nostartfiles
LDFLAGS  += -specs=nano.specs
LDFLAGS  += -specs=nosys.specs
LDFLAGS  += -lc 
LDFLAGS  += -lgcc

SRC_DIR := src
INC_DIR := include

C_SRCS  := $(wildcard $(SRC_DIR)/*.c)
C_OBJS  := $(C_SRCS:.c=.o)

OBJS    := boot.o main.o $(C_OBJS)

all: kernel7.img

boot.o: boot.S
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

main.o: main.c 
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

kernel7.elf: $(OBJS) linker.ld
	$(CROSS)-gcc $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

kernel7.img: kernel7.elf
	$(CROSS)-objcopy kernel7.elf -O binary $@

disasm: kernel7.elf
	$(CROSS)-objdump -D kernel7.elf > kernel7.lst

clean:
	rm -f *.o *.elf *.img *.lst src/*.o