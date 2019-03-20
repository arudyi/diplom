# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 17:26:55 by arudyi            #+#    #+#              #
#    Updated: 2019/03/20 15:19:36 by arudyi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diplom

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INCLUDE_DIR = ./include/
LIB_DIR = ./lib/
SRC = main.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INC := $(LIBFT_DIR)includes/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR) -L./minilibx
CC_FLAGS = -O2
LINK_FLAGS := $(LIBFT_FLAGS)
HEADER_FLAGS := -I $(INCLUDE_DIR) -I $(LIBFT_INC) -I./minilibx
CC := gcc
FRAMEWORK = -lmlx -framework OpenGl -framework Appkit

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FRAMEWORK) $(LINK_FLAGS)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)	

$(OBJ_DIR)%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)