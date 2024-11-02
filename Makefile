# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 21:22:06 by taebkim           #+#    #+#              #
#    Updated: 2024/11/02 20:33:34 by taebkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS	:= -Wall -Wextra -Werror

SRC_DIR := src
GNL_DIR = lib/get_next_line
SRC := main.c error.c hooks.c map.c parse.c memory.c render.c bresenham.c utils.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC)) $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

MLX_DIR = ./mlx
LIBFT_DIR = ./lib/libft

OBJS = $(SRCS:%.c=%.o)

INCLUDE_HEADER  =-Imlx -Iincludes -I$(LIBFT_DIR) -I$(GNL_DIR)

%.o: %.c
	cc $(CFLAGS) $(INCLUDE_HEADER) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) -g $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L$(LIBFT_DIR) -L$(GNL_DIR) -lft -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	
re: fclean all

.PHONY: all, clean, fclean, re