/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:13:09 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/08 18:26:04 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_stack *stack_a, t_stack *stack_b)
{
	sort_1(stack_a, stack_b);
	while (stack_b->len > 0)
		cheapest(stack_a, stack_b);
	while (cost_top(stack_a, find_index(stack_a, get_min(stack_a, NULL))))
	{
		if (find_index(stack_a, get_min(stack_a, NULL)) <= stack_a->len / 2)
			rotate(stack_a);
		else
			r_rotate(stack_a);
	}
}
