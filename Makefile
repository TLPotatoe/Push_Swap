# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 14:16:18 by fmurat--          #+#    #+#              #
#    Updated: 2026/01/07 19:20:27 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

SRCS_DIR    = src
UTILS_DIR   = $(SRCS_DIR)/utils
INSTRU_DIR  = $(SRCS_DIR)/instructions
SORT_DIR 	= $(SRCS_DIR)/sort


SRCS = $(SRCS_DIR)/push_swap.c \
       $(UTILS_DIR)/parse.c \
       $(UTILS_DIR)/utils.c \
       $(UTILS_DIR)/utils_2.c \
       $(UTILS_DIR)/cost.c \
       $(INSTRU_DIR)/px.c \
       $(INSTRU_DIR)/sx.c \
       $(INSTRU_DIR)/rx.c \
       $(INSTRU_DIR)/rrx.c \
       $(INSTRU_DIR)/utils.c \
	   $(SORT_DIR)/sort.c \
	   $(SORT_DIR)/sort_1.c


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
	$(MAKE) -C Libft_C -j

clean:
	rm -f $(OBJS)
	$(MAKE) -C Libft_C clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft_C fclean

re: fclean all

.PHONY: all clean fclean re