# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 17:40:49 by siwonlee          #+#    #+#              #
#    Updated: 2023/01/31 16:50:34 by siwonlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) main.c hexdump.c hexdump_c.c ft_string.c ft_print.c etc.c ft_print_c.c infinite.c -I ft_h.h

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
