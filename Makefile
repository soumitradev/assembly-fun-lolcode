C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c lib/*.c lol/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h lib/*.h lol/*.h)
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o lol/ok.o}

CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
LD = /usr/local/i386elfgcc/bin/i386-elf-ld
GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb

CFLAGS = -g

os-image.bin: boot/boot_sect.bin kernel.bin
	cat $^ > $@

kernel.bin: boot/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

kernel.elf: boot/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^

run: os-image.bin
	qemu-system-i386 -fda $^

debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c -Ilol $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.c: %.lol
	lc2c $< -o $@

%.bin: %.asm
	nasm $< -f bin -I ./boot/ -o $@

clean:
	rm -fr *.bin *.dis *.o os-image.bin *.elf
	rm -fr kernel/*.o boot/*.bin drivers/*.o boot/*.o cpu/*.o lib/*.o lol/*.o