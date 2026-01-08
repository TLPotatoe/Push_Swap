/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:35 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/08 21:09:44 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 3)
		push(stack_a, stack_b);
	if (stack_a->stack[0] > stack_a->stack[1])
		swap(stack_a);
	if (stack_a->stack[1] > stack_a->stack[2])
		r_rotate(stack_a);
	if (stack_a->stack[0] > stack_a->stack[1])
		swap(stack_a);
}

// static void	align_both(t_stack *stack_a, t_stack *stack_b, int i)
// {
// 	int	c_a;
// 	int	c_b;
// 	int	target;

// 	c_a = cost_a(stack_a, stack_b, i);
// 	c_b = cost_b(stack_b, i);
// 	target = next_target(stack_a, stack_b->stack[i]);
// 	target = next_target(stack_a, stack_b->stack[i]);

// 	if (target <= stack_a->len / 2
// 		&& find_index(stack_b, stack_b->stack[i]) <= stack_b->len / 2)
// 		while (--c_a + 1 > 0 && --c_b + 1 > 0)
// 			rotate_both(stack_a, stack_b);

// 	else if (target > stack_a->len / 2
// 		&& find_index(stack_b, stack_b->stack[i]) > stack_b->len / 2)
// 		while (--c_a + 1 > 0 && --c_b + 1 > 0)
// 			r_rotate_both(stack_a, stack_b);
// }

static void	align_stacks(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	c_a;
	int	c_b;
	int	target;

	// align_both(stack_a, stack_b, i);
	target = next_target(stack_a, stack_b->stack[i]);
	c_a = cost_a(stack_a, stack_b, i);
	c_b = cost_b(stack_b, i);
	if (target <= stack_a->len / 2)
		while (--c_a + 1 > 0)
			rotate(stack_a);
	else
		while (--c_a + 1 > 0)
			r_rotate(stack_a);
	if (find_index(stack_b, stack_b->stack[i]) <= stack_b->len / 2)
		while (--c_b + 1 > 0)
			rotate(stack_b);
	else
		while (--c_b + 1 > 0)
			r_rotate(stack_b);
	push(stack_b, stack_a);
}

void	cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_cost;

	min_cost = INT_MAX;
	i = 0;
	while (i < stack_b->len)
	{
		// ft_printf("%d %d %d %d %d\n",
		// stack_b->stack[i],
		// cost_top(stack_b, i),
		// stack_a->stack[next_target(stack_a, stack_b->stack[i])],
		// cost_top(stack_a, next_target(stack_a, stack_b->stack[i])),
		// cost_top(stack_b, i) + cost_top(stack_a, next_target(stack_a, stack_b->stack[i])));
		if (total_cost(stack_a, stack_b, i) < min_cost)
			min_cost = total_cost(stack_a, stack_b, i);
		i++;
	}
	i = 0;
	while (total_cost(stack_a, stack_b, i) != min_cost)
		i++;
	align_stacks(stack_a, stack_b, i);
}
