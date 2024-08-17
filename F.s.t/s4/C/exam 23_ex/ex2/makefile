cc = gcc

cflags = -Wall -Wextra -std=c11

srcs = t.c vn.c un.c
hdrs = suit.h

target = t

all: $(target)
$(target): $(srcs) $(hdrs)
	$(cc) $(cflags) -o $(target) $(srcs)

clean:
	rm -f $(target)




