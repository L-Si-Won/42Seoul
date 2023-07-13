# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 18:29:06 by siwonlee          #+#    #+#              #
#    Updated: 2023/06/19 20:29:32 by siwonlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./

SOURCE = \
	ft_printf.c \
	ft_arg1.c \
	ft_arg2.c \
	ft_str.c \
	ft_itoa.c

OBJECT = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all
