# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 12:32:50 by tmerli            #+#    #+#              #
#    Updated: 2018/05/15 19:51:27 by tmerli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strndup.c\
	  ft_atoi.c\
	  ft_islower.c\
	  ft_lstdelone.c\
	  ft_memchr.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_strcpy.c\
	  ft_strjoin.c\
	  ft_strncmp.c\
	  ft_strsplit.c\
	  ft_bzero.c\
	  ft_isprint.c\
	  ft_lstiter.c\
	  ft_memcmp.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_strdel.c\
	  ft_strlcat.c\
	  ft_strncpy.c\
	  ft_strstr.c\
	  ft_isalnum.c\
	  ft_isupper.c\
	  ft_lstmap.c\
	  ft_memcpy.c\
	  ft_putendl.c\
	  ft_strcat.c\
	  ft_strdup.c\
	  ft_strlen.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_isalpha.c\
	  ft_itoa.c\
	  ft_lstnew.c\
	  ft_memdel.c\
	  ft_putendl_fd.c\
	  ft_strchr.c\
	  ft_strequ.c\
	  ft_strmap.c\
	  ft_strnew.c\
	  ft_strtrim.c\
	  ft_isascii.c\
	  ft_lstadd.c\
	  ft_memalloc.c\
	  ft_memmove.c\
	  ft_putnbr.c\
	  ft_putnbrdl.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_strmapi.c\
	  ft_strnstr.c\
	  ft_tolower.c\
	  ft_isdigit.c\
	  ft_lstdel.c\
	  ft_memccpy.c\
	  ft_memset.c\
	  ft_putnbr_fd.c\
	  ft_strcmp.c\
	  ft_striteri.c\
	  ft_strncat.c\
	  ft_strrchr.c\
	  ft_toupper.c\
	  ft_abs.c\

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	gcc -c $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
