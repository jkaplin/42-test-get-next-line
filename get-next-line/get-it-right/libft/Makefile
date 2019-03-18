# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 10:05:39 by jkaplin           #+#    #+#              #
#    Updated: 2019/03/06 20:07:33 by jkaplin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -I. -c

SRC =	ft_atoi.c		\
		ft_abs.c		\
		ft_average.c	\
		ft_bzero.c		\
		ft_idigits.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_islower.c	\
		ft_isprint.c	\
		ft_isspace.c	\
		ft_isupper.c	\
		ft_itoa.c		\
		ft_lstadd.c		\
		ft_lstdel.c		\
		ft_lstdelone.c	\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_lstnew.c		\
		ft_max.c		\
		ft_memalloc.c	\
		ft_memccpy.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memdel.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_min.c		\
		ft_pow.c		\
		ft_putchar.c	\
		ft_putchar_fd.c	\
		ft_putendl.c	\
		ft_putendl_fd.c	\
		ft_putnbr.c		\
		ft_putnbr_fd.c	\
		ft_putstr.c		\
		ft_putstr_fd.c	\
		ft_sqrt.c		\
		ft_strcapital.c	\
		ft_strcat.c		\
		ft_strchr.c		\
		ft_strclr.c		\
		ft_strcmp.c		\
		ft_strcpy.c		\
		ft_strdel.c		\
		ft_strdup.c		\
		ft_strequ.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlasti.c	\
		ft_strlcat.c	\
		ft_strlen.c		\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strncat.c	\
		ft_strncmp.c	\
		ft_strncpy.c	\
		ft_strnequ.c	\
		ft_strnew.c		\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strsplit.c	\
		ft_strstr.c		\
		ft_strsub.c		\
		ft_strtrim.c	\
		ft_tolower.c	\
		ft_toupper.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	gcc $(CFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

