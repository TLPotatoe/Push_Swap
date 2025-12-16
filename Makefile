# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 14:16:18 by fmurat--          #+#    #+#              #
#    Updated: 2025/12/16 18:00:18 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

SRCS := src/parse.c \
	src/push_swap.c \
	src/utils/utils.c \
	src/instructions/px.c \
	src/instructions/sx.c \
	src/instructions/rx.c \
	src/instructions/rrx.c \
	src/instructions/utils.c

HEADER := -I includes \
		-I Libft_C

ifndef DEBUG
	CFLAGS := -Wall -Wextra -Werror -g $(HEADER)
else
	CFLAGS := -g $(HEADER)
endif

NAME := push_swap
LIBFT := Libft_C/libft.a

LIBS := $(LIBFT)

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

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