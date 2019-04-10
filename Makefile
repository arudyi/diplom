# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 17:26:55 by arudyi            #+#    #+#              #
#    Updated: 2019/04/10 23:47:04 by arudyi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diplom

SRC_DIR = ./src/
INCLUDE_DIR = ./include/
LIB_DIR = ./lib/
SRC = main.c
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INC := $(LIBFT_DIR)includes/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR) -L./usr/X11/lib/usr/X11/lib/libmlx.a -lXext -lX11
CC_FLAGS = -O2
LINK_FLAGS := $(LIBFT_FLAGS)
HEADER_FLAGS := -I $(INCLUDE_DIR) -I $(LIBFT_INC) -I./minilibx
CC := gcc
FRAMEWORK = -lmlx

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) -o $(NAME) src/$(SRC) $(FRAMEWORK) $(LINK_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
