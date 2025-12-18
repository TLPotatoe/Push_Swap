/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:59:50 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/18 18:23:15 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	slide_left(t_stack *stack)
{
	int	i;

	i = 0;
	// if (stack->len < 0)
	// 	return ;
	while (i < stack->len - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		(void)i++;
	}
	if (stack->len > 0)
		(void)stack->len--;
}

void	slide_right(t_stack *stack)
{
	int	i;

	i = stack->len;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		(void)i--;
	}
	if (stack->len < stack->max_len)
		(void)stack->len++;
}
