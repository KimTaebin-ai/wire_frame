# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 21:22:06 by taebkim           #+#    #+#              #
#    Updated: 2024/11/06 20:32:46 by taebkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS	:= -Wall -Wextra -Werror

SRC_DIR := src
OBJ_DIR := obj
GNL_DIR = lib/get_next_line
SRC := main.c color.c color_utils.c draw.c error.c hooks.c parse.c projection.c utils.c utils2.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC)) $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

MLX_DIR = ./mlx/build
LIBFT_DIR = ./lib/libft

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o) $(notdir $(GNL_DIR)/get_next_line.o) $(notdir $(GNL_DIR)/get_next_line_utils.o))

INCLUDE_HEADER  = -I./mlx/include/MLX42 -Iincludes -I$(LIBFT_DIR) -I$(GNL_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_HEADER) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) -g $(OBJS) -L$(MLX_DIR) -lmlx42 -L$(LIBFT_DIR) -lft -L/usr/lib -lXext -lX11 -lm -lz -lglfw -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	
re: fclean all

.PHONY: all clean fclean re
