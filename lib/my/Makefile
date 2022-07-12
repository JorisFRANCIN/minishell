##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile the lib
##

SRC	=	my_put_nbr.c	\
		my_put_nbr2.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_put_nbr2.c	\
		my_putstr2.c	\
		my_put_nbr_base.c	\
		my_put_nbr_binary.c	\
		my_put_nbr_hex.c	\
		my_printf.c	\
		my_strlen.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_str_to_word_array.c	\
		my_atoi.c	\
		my_clean_str.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp my.h ../../includes
	@cp $(NAME) ../../

clean:
	@rm -f $(OBJ)

my_clean:
	@rm -f *~
	@rm -f *#
	@rm -f *.#

fclean: clean
	@rm -f $(NAME)
	@rm -f ../../libmy.a
	@rm -f ../../includes/my.h

re:	fclean all
