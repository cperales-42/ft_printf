CC = cc 
CFLAGS = -Wall -Wextra -Werror 
AR = ar 
ARFLAGS = rcs
NAME = libftprintf.a
SOURCES = ft_putchar_pf.c ft_printf_utils.c ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

#REGLAS

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re