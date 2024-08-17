cc= gcc

cflags= -Wall -Wextra -std=c11

src= t.c function.c
hdr= function.h

tar=t
all: $(tar)
$(tar): $(src) $(hdr)
	$(cc) $(cflags) -o $(tar) $(src)

clean:
	rm -f $(tar) 

.phony: all clean


















