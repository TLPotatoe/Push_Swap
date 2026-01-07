/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:17:42 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/07 18:44:50 by tlamit           ###   ########.fr       */
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

static int	cost_top(t_stack *stack, int itarget)
{
	if (itarget <= stack->len / 2)
		return (itarget);
	else
		return (stack->len - itarget);
}

// i = -1;
// while (++i < stack_b->len)
// 	ft_printf("TL B: %d INDEX: %d VALUE:%d\n", stack_b->stack[i],
// 		target_list[i], stack_a->stack[next_target(stack_a,
// 			stack_b->stack[i])]);

void	bring_top(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_index;
	int	min_cost;

	i = -1;
	while (++i < stack_b->len)
	{
		ft_printf("%d %d %d %d %d\n", stack_b->stack[i], cost_top(stack_b, i),
			stack_a->stack[next_target(stack_a, stack_b->stack[i])],
			cost_top(stack_a, next_target(stack_a, stack_b->stack[i])),
			cost_top(stack_b, i) + cost_top(stack_a, next_target(stack_a,
					stack_b->stack[i])));
	}
}
