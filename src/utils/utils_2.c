/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:17:42 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/06 19:27:28 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_target(t_stack *stack_a, int origin)
{
	int	index;
	int	target;

	index = 0;
	target = get_max(stack_a);
	while (index < stack_a->len)
	{
		if (stack_a->stack[index] >= origin && stack_a->stack[index] < target)
			target = stack_a->stack[index];
		index++;
	}
	index = 0;
	while (index < stack_a->len && stack_a->stack[index] != target)
		index++;
	return (index);
}

void	evaluate_cost(t_stack *stack_a, t_stack *stack_b, int *cost_list)
{
	int	i;
	int	j;
	int	target;

	while (i < stack_a->max_len)
	{
		cost_list[i] = next_target(stack_a, stack_b->stack[i]);
		i++;
	}
	for (int i = 0; i < stack_a->max_len; i++)
	{
		ft_printf("%d ", cost_list[i]);
	}
	ft_printf("\n");
}
