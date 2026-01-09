/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:19:58 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/09 14:30:48 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_top(t_stack *stack, int itarget)
{
	int	i;
	int	j;

	i = itarget;
	j = itarget;
	itarget = 0;
	while (i && j != stack->len)
	{
		i--;
		j++;
		itarget++;
	}
	return (itarget);
}

int	total_cost(t_stack *stack_a, t_stack *stack_b, int i)
{
	return (cost_a(stack_a, stack_b, i) + cost_b(stack_b, i));
}

int	cost_a(t_stack *stack_a, t_stack *stack_b, int i)
{
	return (cost_top(stack_a, next_target(stack_a, stack_b->stack[i])));
}

int	cost_b(t_stack *stack_b, int i)
{
	return (cost_top(stack_b, i));
}
