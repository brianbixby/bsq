# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbixby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 12:28:32 by bbixby            #+#    #+#              #
#    Updated: 2018/07/09 14:12:44 by bbixby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = src/main.c 
LIBSRC = src/helpers.c src/helpers2.c
FLAGS = gcc -Wall -Werror -Wextra
OUTPUT = helpers.o helpers2.o
INCLUDE = include/

all: $(NAME)

$(NAME):
	$(FLAGS) -I$(INCLUDE) -c $(LIBSRC)
	ar rc libft.a $(OUTPUT)
	ranlib libft.a

	$(FLAGS) -I$(INCLUDE) $(SRC) libft.a -o $(NAME)

clean:
	/bin/rm -f $(OUTPUT)

fclean: clean
	/bin/rm -f $(NAME) libft.a

re: fclean all
