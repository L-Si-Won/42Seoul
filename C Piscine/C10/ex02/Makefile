# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:06:56 by siwonlee          #+#    #+#              #
#    Updated: 2023/01/27 20:10:30 by siwonlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) ft_tail.c ft_string.c ft_exception.c -I ft_h.h

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
