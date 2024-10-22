# Variables
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SOURCES =	ft_libft_utils.c \
			ft_print_char.c \
			ft_print_hex_nbr.c \
			ft_print_nbr.c \
			ft_print_str.c \
			ft_print_unsigned_nbr.c \
			ft_print_voidptr.c \
			ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) rcs $(NAME) $(OBJECTS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
