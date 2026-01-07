/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:35 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/07 19:14:40 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a, stack_b);
	while (stack_a->len > 3)
		push(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	if (stack_a->stack[0] > stack_a->stack[1])
		swap(stack_a);
	if (stack_a->stack[1] > stack_a->stack[2])
		r_rotate(stack_a);
	if (stack_a->stack[0] > stack_a->stack[1])
		swap(stack_a);
	print_stack(stack_a, stack_b);
}

void	cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_cost;

	min_cost = 2147483647;
	i = 0;
	while (i < stack_b->len)
		if (total_cost(stack_a, stack_b, i) < min_cost)
			min_cost = total_cost(stack_a, stack_b, i++);
}
