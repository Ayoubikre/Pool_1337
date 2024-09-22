# -*- Makfile -*-

cc = gcc

cflags = -Wall -Wextra -Werror

INCS	= includes

head = $(shell find ./includes -name "*.h" -type f)
# head = $(wildcard ./includes/*.h)

srcs = $(shell find ./src -name "*.c" -type f)
# srcs = $(wildcard ./srcs/*.c)

objc = $(srcs:.c=.o)

target = libft.a

all: $(target)

$(target): $(objc)
	ar rc $(target) $(objc)
	ranlib $(target)
#	ar t $(target)


%.o: %.c $(head)
	$(cc) $(cflags) -c -o $@ $<
# %.o: %.c
# 	$(cc) $(cflags) -c -o $@ $^ -I $(INCS)


clean:
	rm -rf $(objc)

fclean:
	rm -rf $(objc) $(target)
# fclean: clean
# 	rm -rf ${target}

re:
	make fclean
	make all
# re: fclean all

.PHONY: all clean
