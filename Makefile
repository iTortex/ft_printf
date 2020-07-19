SRC = ft_printf.c ft_strlen.c ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_itoa.c ft_strncmp.c ft_calloc.c ft_utoa.c writeforp.c writeforu.c writeforxX.c writeforc.c writeforid.c writefors.c workwithdot.c width.c ft_strlcpy.c ft_strchr.c
OBJ = ft_printf.o ft_strlen.o ft_atoi.o ft_putnbr_fd.o ft_putstr_fd.o ft_itoa.o ft_strncmp.o ft_calloc.o ft_utoa.o writeforp.o writeforu.o writeforxX.o writeforc.o writeforid.o writefors.o workwithdot.o width.o ft_strlcpy.o ft_strchr.o

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libftprintf.a $(OBJ)
	ranlib libftprintf.a

%.o: %.c
	clang -Wall -Wextra -Werror -o $@ -c $<

test:
	clang -Wall -Wextra -Werror $(SRC)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f libftprintf.a

re: fclean all

.PHONY: all clean fclean re bonus