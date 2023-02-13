# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 10:32:11 by siwonlee          #+#    #+#              #
#    Updated: 2023/01/24 10:54:14 by siwonlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Werror -Wextra 

NAME=ft_display_file

OBJS=main.o

SRCS=main.c

all : $(NAME)

.c.o :
	gcc $(CFLAGS) -c $(SRCS)

$(NAME) : $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
