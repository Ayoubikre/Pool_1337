cc = gcc

cflags = -Wall -Wextra -Werror

src = $(shell find . -name "*.c" -type f)

objc = $(src:.c=.o)

target = t

all: $(target) clean

$(target): $(objc)
	@$(cc) $(cflags) -o $(target) $(objc)

%.o: %.c
	@$(cc) $(cflags) -c -o $@ $<

clean:
	@rm -rf *.o

re: 
	@rm -rf $(target)
	@make all


