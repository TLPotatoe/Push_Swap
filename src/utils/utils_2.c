/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:17:42 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/07 17:15:01 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	next_target(t_stack *stack_a, int origin)
{
	int	i;
	int	target;

	target = get_max(stack_a, NULL);
	if (origin > target)
		return (find_index(stack_a, get_min(stack_a, NULL)));
	i = 0;
	while (i < stack_a->len)
	{
		if (stack_a->stack[i] >= origin && stack_a->stack[i] <= target)
			target = stack_a->stack[i];
		i++;
	}
	return (find_index(stack_a, target));
}

void	evaluate_cost(t_stack *stack_a, t_stack *stack_b, int *target_list)
{
	int	i;

	i = 0;
	while (i < stack_b->len)
	{
		target_list[i] = next_target(stack_a, stack_b->stack[i]);
		ft_printf("TARGET FOR A:%d <- %d\n", stack_a->stack[target_list[i]],
			stack_b->stack[i]);
		i++;
	}
}
