AS=i686-elf-as
CC=i686-elf-gcc
CXX=i686-elf-g++

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS=-ffreestanding -O2 -nostdlib 

SRC := $(wildcard *.c lib/*.c) 
SRC_ASM := $(wildcard *.s) 
# OBJs are under out/ and out/lib directory

OBJ := $(patsubst %.c, out/%.o, $(SRC))
OBJ_ASM := $(patsubst %.s, out/%.o, $(SRC_ASM))

EXE := boot.bin

.PHONY: all

all: clean out build virt

# prepare out/ directory
out:
	@mkdir -p out
	@mkdir -p out/lib

# build .c files to .o files
out/%.o: %.c
	@echo "[CC] $< -> $@"
	@$(CC) -c $< -o $@ $(CFLAGS)

out/%.o: %.s 
	@echo "[AS] $< -> $@"
	@$(AS) $< -o $@

# build sources in out/ directory
build: $(OBJ_ASM) $(OBJ)
	@echo "[LD] $^ -> $(EXE)"
	@$(CC) -T linker.ld -o $(EXE) $(LDFLAGS) $^ -lgcc

# clean up
clean:
	@rm -rf out boot.bin

virt: $(EXE)
	@echo "[QEMU] -kernel $(EXE)"
	@qemu-system-i386 -kernel boot.bin


