# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/08 00:05:18 by sdahmouc          #+#    #+#              #
#    Updated: 2017/09/12 05:07:34 by sdahmouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LFT = libft/libft.a

MLX = minilibx

LIBS = $(LFT) -L

HPATH = -I./

SRC = main.c \
	  draw.c \
	  map.c \
	  music.c \
	  hook2.c \
	  hook.c

CC = gcc -g -Wall -Werror -Wextra

C_MLX = $(MLX) -lmlx -framework OpenGL -framework AppKit

AR = ar - cvq libft.a

RM = rm -rf

SRCDIR = $(addprefix ./src/, $(SRC))

OBJDIR = obj

OBJ = $(addprefix ./$(OBJDIR)/, $(SRC:.c=.o))

$(NAME):
	@make -C libft
	@$(CC) -c $(SRCDIR)
	@mkdir -p $(OBJDIR) && mv $(SRC:.c=.o) ./$(OBJDIR)/
	@$(CC) -o $(NAME) $(OBJ) $(LIBS) $(C_MLX) $(HPATH)

all: $(NAME)

clean:
	@$(RM) $(OBJDIR)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean
	@make re -C libft
	@make all
	@make clean

.PHONY: all clean fclean
