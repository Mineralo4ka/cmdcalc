TARGET := bin/cmdcalc
CC := gcc
CFLAGS := -Wall -Werror -c

all: $(TARGET)

$(TARGET): build/src/main.o build/src/function.o
		$(CC) build/src/main.o build/src/function.o -o $@


build/src/main.o: src/main.c
		$(CC) $(CFLAGS) src/main.c -o $@ 

build/src/function.o: src/function.c
		$(CC) $(CFLAGS) src/function.c -o $@ 


.PHONY: all clean
clean:	
	rm -rf build/src/*.o
	rm -rf bin/*