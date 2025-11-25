# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 14:16:18 by fmurat--          #+#    #+#              #
#    Updated: 2025/11/24 16:14:40 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

SRC_DIR = src/
SRCS = $(SRC_DIR)parse.c \
	$(SRC_DIR)push_swap.c 

CFLAGS = -Wall -Wextra -Werror -g \
		-I includes \
		-I Libft_C/ \
		-I Libft_C/ft_printf/ \
		-I Libft_C/get_next_line/

NAME = push_swap
LIBFT = Libft_C/libft.a
LDFLAGS = $(LIBFT)

OBJ_DIR = objs/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME):  $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p objs/
	$(CC) $(CFLAGS) -c -o $@ $<


$(LIBFT):
	$(MAKE) -C Libft_C

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C Libft_C clean

fclean:
	rm -f $(NAME)
	$(MAKE) -C Libft_C fclean
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re