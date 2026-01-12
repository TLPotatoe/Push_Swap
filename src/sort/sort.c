/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:13:09 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/12 17:59:36 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack_a)
{
	int	i;
	int	min;

	i = 0;
	min = -2147483648;
	while (i < stack_a->len)
	{
		if (stack_a->stack[i] > min)
			min = stack_a->stack[i];
		if (stack_a->stack[i] < min)
			return (0);
		i++;
	}
	return (1);
}

void	sort_main(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	sort_1(stack_a, stack_b);
	while (stack_b->len > 0)
		cheapest(stack_a, stack_b);
	while (find_index(stack_a, get_min(stack_a, NULL)))
	{
		if (find_index(stack_a, get_min(stack_a, NULL)) <= stack_a->len / 2)
			rotate(stack_a);
		else
			r_rotate(stack_a);
	}
}
