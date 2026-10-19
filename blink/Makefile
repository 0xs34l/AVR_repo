
MCU = atmega328p
F_CPU = 16000000UL
PORT = /dev/ttyACM0
BAUD = 115200

CC = avr-gcc
OBJCOPY = avr-objcopy
PROGRAMMER = avrdude

CFLAGS = -Wall -Wextra -Os -mmcu=$(MCU) \
         -DF_CPU=$(F_CPU)

.PHONY: all flash clean

all: main.hex

main.elf: main.c
	$(CC) $(CFLAGS) main.c -o main.elf

main.hex: main.elf
	$(OBJCOPY) -O ihex -j .text -j .data main.elf main.hex

flash: main.hex
	$(PROGRAMMER) -c arduino -p m328p -P $(PORT) -b $(BAUD) \
		-U flash:w:main.hex:i

clean:
	rm -f main.elf main.hex
