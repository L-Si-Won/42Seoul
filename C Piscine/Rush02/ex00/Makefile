# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 07:24:55 by seonglim          #+#    #+#              #
#    Updated: 2023/01/29 18:00:58 by siwonlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) check.c dict.c init.c main.c print.c str.c give.c -I ft.h

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
