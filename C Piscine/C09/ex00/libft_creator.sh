# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwonlee <tldnjs0821222@naver.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:31:40 by siwonlee          #+#    #+#              #
#    Updated: 2023/01/23 14:46:29 by siwonlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
gcc -c ft_putchar.c ft_strcmp.c ft_swap.c ft_putstr.c ft_strlen.c
ar rc libft.a ft_putchar.o ft_strcmp.o ft_swap.o ft_putstr.o ft_strlen.o
