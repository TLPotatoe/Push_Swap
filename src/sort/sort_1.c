/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:35 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/06 19:19:02 by tlamit           ###   ########.fr       */
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
	// while (!next_target(stack_a, stack_b->stack[0]) && stack_b->len)
	// {
	// 	ft_printf("Tar A I:%d\n", next_target(stack_a, stack_b->stack[0]));
	// 	push(stack_b, stack_a);
	// 	print_stack(stack_a, stack_b);
	// }
	print_stack(stack_a, stack_b);
}

void	sort_2(t_stack *stack_a, t_stack *stack_b, int *cost_list)
{
}