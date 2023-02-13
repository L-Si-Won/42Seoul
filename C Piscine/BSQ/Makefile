# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 17:24:33 by siwonlee          #+#    #+#              #
#    Updated: 2023/02/01 22:16:26 by jihshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) main.c str.c c_arr.c square.c map_exception.c map_init.c i_arr.c no_parm.c no_parm_c_arr.c -I ft_h.h

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
