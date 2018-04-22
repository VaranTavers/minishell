# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 18:08:35 by ztasnadi          #+#    #+#              #
#    Updated: 2018/04/18 16:29:10 by ztasnadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
INC = ./includes/
LIB_DIR = ./libft/
LIB_COMP = ./libft/libft.a
SRC = main.c ft_interpret.c ft_smartsplit.c ft_cd.c ft_echo.c ft_env.c \
	  ft_exit.c ft_setenv.c ft_unsetenv.c enviroment.c pair.c ft_smartsearch.c\
	  ft_dequotify.c ft_path.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

comp_lib:
	make -C $(LIB_DIR)

clean_lib:
	make -C $(LIB_DIR) clean

fclean_lib:
	make -C $(LIB_DIR) fclean

re_lib:
	make -C $(LIB_DIR) re

$(NAME): comp_lib
	gcc -I $(LIB_DIR) -I $(INC) -Wall -Wextra -Werror -c $(SRC)
	gcc $(OBJ) $(LIB_COMP) -o $(NAME)

clean: clean_lib
	rm -f $(OBJ)

fclean: clean fclean_lib
	rm -f $(NAME)

re:	fclean all
