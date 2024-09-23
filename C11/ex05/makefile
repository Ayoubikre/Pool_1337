# -*- MakeFile -*-

cc = gcc

cflags = -Wall -Wextra -Werror -I ./includes

src = $(shell find ./src -name "*.c" -type f)
allsrc= main.c $(src)

objc = $(allsrc:.c=.o)

target = do-op

all: $(target)

$(target): $(objc)
	$(cc) $(cflags) -o $(target) $(objc)


%.o: %.c
	$(cc) $(cflags) -c -o $@ $<


clean : $(objc)
	rm -rf $(objc)

fclean: clean
	rm -rf $(target)

re: 
	make fclean
	make all

.PHONY: all clean fclean re
