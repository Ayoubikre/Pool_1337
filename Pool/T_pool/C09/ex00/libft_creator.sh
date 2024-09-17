


                        # methode 1 : run manully

gcc -c  -Wall -Werror -Wextra  ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c ;  ar rc libft.a *.o ; runlib libft.a

                        # methode 2 : run auto

find . -name "*.c" -type f -exec gcc -c -Wall -Werror -Wextra {} \;
ar rc libft.a *.o
find . -name "*.o" -type f -delete


                        # explantion :

        ;   :   the simicolone let the comands run after each other sepreatly 
        -c  :   dont link the .o files into one file 
    ar rc   :   ar - archive
                r  - replace the .o files withe new version 
                c  - create libft.a 
                t  - show all .o inside of libft.a
    runlib  :   index link fro old system "not need for new one"
