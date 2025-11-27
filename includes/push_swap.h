/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:49:33 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/27 23:57:35 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int *stack;
	int max_len;
	int len;
	char id;
} t_stack;

t_stack *parse(char **av);

char *ft_strcharset(char *s1, char *charset);

#endif
