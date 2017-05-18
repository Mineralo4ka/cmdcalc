TARGET := bin/cmdcalc
CC := gcc
CFLAGS :=  -Wall -Werror

all: $(TARGET)

$(TARGET): src/main.c
	$(CC) $(CFLAGS) src/main.c -o $@


.PHONY: all clean

clean:
	rm -f bin/*