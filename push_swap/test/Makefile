CC = clang
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean

all: main.c \

sort_program: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f main *.o