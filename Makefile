##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

NAME	=	mysh

DIR_INIT	=	sources/init_src/

DIR_ADV	=	sources/adv_src/

DIR_BUILTINS	=	sources/builtins/

DIR_BIN	=	sources/bin_command/

INIT_SRC	=	$(DIR_INIT)minishell.c	\
			$(DIR_INIT)init_struct.c	\
			$(DIR_INIT)my_params_to_list.c	\

ADV_SRC	=	$(DIR_ADV)minishell_basic.c	\
			$(DIR_ADV)minishell_redirect.c	\

BUILTINS_SRC	=	$(DIR_BUILTINS)builtins.c	\
			$(DIR_BUILTINS)cd_command.c	\
			$(DIR_BUILTINS)setenv_command.c	\
			$(DIR_BUILTINS)unsetenv_command.c	\

BIN_SRC	=	$(DIR_BIN)exec_bin_command.c	\

SRC	=	sources/main.c	\
		$(INIT_SRC)	\
		$(ADV_SRC)	\
		$(BUILTINS_SRC)	\
		$(BIN_SRC)	\
		sources/count_arg.c	\
		sources/exit_case.c	\
		sources/free_all.c

CPPFLAGS	=	-I./includes

LDFLAGS	=	-L./ -lmy

CC	=	gcc -Wall -Wextra

all: $(NAME)

$(NAME):
	@make -C lib/my
	@$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS)

clean:
	@make clean -C lib/my

my_clean: fclean
	@make my_clean -C lib/my
	@rm -f *~
	@rm -f includes/*~
	@rm -f sources/*~
	@rm -f sources/*#
	@rm -f sources/*.#
	@rm -f *#
	@rm -f *.#

fclean: clean
	@make fclean -C lib/my
	@rm -f $(NAME)

re: fclean all

.PHONY: clean my_clean fclean re all
