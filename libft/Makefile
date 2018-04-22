# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 18:08:35 by ztasnadi          #+#    #+#              #
#    Updated: 2018/04/15 17:53:21 by ztasnadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INC = ./includes/
SRC = ft_printf.c ft_dn.c ft_putbinf.c ft_atoi.c ft_strlen.c ft_putcharf.c \
	  ft_puthexf.c ft_putoctf.c ft_putunbrf.c ft_strlen.c ft_percent.c \
	  ft_putnbrf.c ft_putptrf.c ft_putwcharf.c ft_putstrf.c ft_putwstrf.c \
	  ft_putstr.c ft_putchar.c ft_memcpy.c ft_printf_parser.c ft_putwstr.c \
	  ft_update_conv.c ft_memset.c ft_bzero.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	  ft_strsplit.c ft_itoa.c ft_putendl.c ft_nbrlen.c\
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	  ft_lstiter.c ft_lstmap.c ft_lstpushback.c ft_lstsize.c ft_lstfind.c \
	  ft_match.c ft_nmatch.c ft_lstsort.c get_next_line.c ft_lstelem.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -I $(INC) -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
