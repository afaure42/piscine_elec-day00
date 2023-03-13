

SRCS = main.c

BINS = $(SRCS:.c=.bin)
HEXES = $(BINS:.bin=.hex)

CC = avr-gcc


F_CPU = 1000000UL
CFLAGS = -D F_CPU=$(F_CPU)

$(BINS): $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(HEXES): $(BINS)
	avr-objcopy -O ihex $< $@

hex: $(HEXES)


flash: hex

all: flash

clean:
	rm -rf $(BINS) $(HEXES)
	