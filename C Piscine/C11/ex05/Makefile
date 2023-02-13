# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 18:27:34 by siwonlee          #+#    #+#              #
#    Updated: 2023/01/26 10:22:39 by siwonlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

all : $(NAME)

$(NAME) : atoi_putnbr.c operator.c main.c
	gcc -Wall -Wextra -Werror -o $(NAME) atoi_putnbr.c operator.c main.c

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
