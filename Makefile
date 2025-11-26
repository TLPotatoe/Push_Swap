# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 14:16:18 by fmurat--          #+#    #+#              #
#    Updated: 2025/11/26 18:30:07 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

SRCS = src/parse.c \
	src/push_swap.c 

HEADER = -I includes \
		-I Libft_C/

CFLAGS = -Wall -Wextra -Werror -g $(HEADER)

NAME = push_swap
LIBFT = Libft_C/libft.a
LDFLAGS = $(LIBFT)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C Libft_C

clean:
	rm -f $(OBJS)
	$(MAKE) -C Libft_C clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft_C fclean

re: fclean all

.PHONY: all clean fclean re