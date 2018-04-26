# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:38:31 by tmerli            #+#    #+#              #
#    Updated: 2018/04/20 16:37:29 by tmerli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = bfs.c\
	  check.c\
	  check1.c\
	  get_next_line.c\
	  lemin.c\
	  move.c\
	 parsing.c\
	 parsing2.c\
	 path_finding.c\
	 send_ants.c\
	 utils.c\

LIBPATH = libft/

LIB = libft.a

HEADER = lemin.h\
		 get_next_line.c\

FLAGS = -Wall -Wextra -Werror

CC= gcc

OBJ = $(SRC:.c=.o)

all : $(LIB) $(NAME)

$(LIB) :
	make -C $(LIBPATH)

$(NAME) : $(SRC) $(HEADER)
	$(CC) -c $(FLAGS) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIBPATH)$(LIB)

clean :
	make clean -C $(LIBPATH)
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIBPATH)$(LIB)
	rm -f $(NAME)

re : fclean all
