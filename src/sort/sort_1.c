/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:02:35 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/06 17:49:45 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1(t_stack *stack_a, t_stack *stack_b)
{
	print_stack(stack_a, stack_b);
	while (stack_a->len > 3)
		push(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	while (!next_target(stack_a, stack_b) && stack_b->len)
	{
		ft_printf("Tar A I:%d", next_target(stack_a, stack_b));
		push(stack_b, stack_a);
		print_stack(stack_a, stack_b);
	}
	// print_stack(stack_a, stack_b);
}
