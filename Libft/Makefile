# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwonlee <siwonlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 21:38:40 by siwonlee          #+#    #+#              #
#    Updated: 2023/05/11 03:31:55 by siwonlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = \
	ft_substr.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_putendl_fd.c \
	ft_isalpha.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_isdigit.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c

BONUS = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJECT = $(SOURCE:.c=.o)

BONUS_OBJECT = $(BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./

ifdef WITH_BONUS
	OBJ_FILES = $(OBJECT) $(BONUS_OBJECT)
else
	OBJ_FILES = $(OBJECT)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

bonus :
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJECT) $(BONUS_OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
