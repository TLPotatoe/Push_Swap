# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 14:16:18 by fmurat--          #+#    #+#              #
#    Updated: 2026/01/12 15:43:20 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

SRCS_DIR    = src
UTILS_DIR   = $(SRCS_DIR)/utils
INSTRU_DIR  = $(SRCS_DIR)/instructions
INSTRU_BONUS_DIR = $(SRCS_DIR)/bonus/instructions
SORT_DIR 	= $(SRCS_DIR)/sort

SRCS_UTILS = $(UTILS_DIR)/parse.c \
       $(UTILS_DIR)/utils.c \
       $(UTILS_DIR)/utils_2.c \
       $(UTILS_DIR)/cost.c \
       $(INSTRU_DIR)/utils.c

SRCS_COMMON = $(SRCS_UTILS) \
	   $(SORT_DIR)/sort.c \
	   $(SORT_DIR)/sort_utils.c

SRCS = $(SRCS_DIR)/push_swap.c \
	$(INSTRU_DIR)/px.c \
	$(INSTRU_DIR)/sx.c \
	$(INSTRU_DIR)/rx.c \
	$(INSTRU_DIR)/rrx.c \
	$(SRCS_COMMON)

BONUS_SRCS = $(SRCS_DIR)/bonus/checker.c \
	$(INSTRU_BONUS_DIR)/px.c \
	$(INSTRU_BONUS_DIR)/sx.c \
	$(INSTRU_BONUS_DIR)/rx.c \
	$(INSTRU_BONUS_DIR)/rrx.c \
	$(SRCS_UTILS)

HEADER := -I includes \
		-I Libft_C

ifndef DEBUG
	CFLAGS := -Wall -Wextra -Werror -g $(HEADER)
else
	CFLAGS := -g $(HEADER)
endif

NAME := push_swap
BONUS_NAME := checker
LIBFT := Libft_C/libft.a

LIBS := $(LIBFT)

OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C Libft_C -j

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBS)
	$(CC) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C Libft_C clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C Libft_C fclean

re: fclean all

.PHONY: all clean fclean re