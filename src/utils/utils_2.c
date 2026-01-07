/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:17:42 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/07 19:42:42 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i <= stack->len / 2)
	{
		if (stack->stack[i] == value)
			return (i);
		if (stack->stack[stack->len - i] == value)
			return (stack->len - i);
		i++;
	}
	return (-1);
}

// i = stack_a->len + 1;
// while (--i > stack_a->len / 2)
// 	if (stack_a->stack[i] >= origin && stack_a->stack[i] <= target_v)
// 	{
// 		target_v = stack_a->stack[i];
// 		target_i = i;
// 	}

int	next_target(t_stack *stack_a, int origin)
{
	int	i;
	int	target_v;
	int	target_i;

	target_v = get_max(stack_a, NULL);
	if (origin > target_v)
		return (find_index(stack_a, get_min(stack_a, NULL)));
	i = 0;
	while (i <= stack_a->len)
	{
		if (stack_a->stack[i] >= origin && stack_a->stack[i] <= target_v)
		{
			target_v = stack_a->stack[i];
			target_i = i;
		}
		i++;
	}
	return (target_i);
}
