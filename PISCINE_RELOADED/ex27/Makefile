# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 10:59:34 by sdahmouc          #+#    #+#              #
#    Updated: 2016/11/04 13:30:16 by sdahmouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

CC = gcc

CFLAG = -Wall -Werror -Wextra

SRCS = ft_strlen.c\
		ft_putstr.c\
		display_file.c\
		ft_putchar.c\
		main.c

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAG) $(SRCS) -o ft_display_file

clean :

fclean : clean
		rm -rf $(NAME)

re : all
