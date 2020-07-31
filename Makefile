SRC = ft_printf.c ft_strlen.c ft_atoi.c ft_itoa.c ft_bzero.c ft_calloc.c ft_utoa.c transforx.c transforp.c writeforprcnt.c writeforp.c writeforu.c writeforxx.c writeforc.c writeforid.c writefors.c workwithdot.c width.c
OBJ = ft_printf.o ft_strlen.o ft_atoi.o ft_itoa.o ft_bzero.o ft_calloc.o ft_utoa.o transforx.o transforp.o writeforprcnt.o writeforp.o writeforu.o writeforxx.o writeforc.o writeforid.o writefors.o workwithdot.o width.o

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libftprintf.a $(OBJ)
	ranlib libftprintf.a

%.o: %.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f libftprintf.a

re: fclean all

.PHONY: all clean fclean re bonus