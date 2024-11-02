# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 23:49:28 by taebkim           #+#    #+#              #
#    Updated: 2024/10/15 02:16:35 by taebkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c func.c func2.c convert_hex.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -I.

all : $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp  ./libft/libft.a $(NAME)
	ar -rcs $@ $^
	
%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean :
	$(MAKE) -C ./libft fclean
	make clean
	rm -f $(NAME) 

re : 
	make fclean
	make all

.PHONY : all clean fclean re