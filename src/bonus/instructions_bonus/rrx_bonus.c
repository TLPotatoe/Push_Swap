/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:40:55 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/12 16:11:30 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack *stack)
{
	int	temp;

	temp = stack->stack[stack->len - 1];
	slide_right(stack);
	if (stack->len > 0)
		stack->len--;
	stack->stack[0] = temp;
}

int	r_rotate_bonus(t_stack *stack)
{
	rrotate(stack);
	return (2);
}

int	r_rotate_both_bonus(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0 || stack_b->len == 0)
		return (3);
	rrotate(stack_a);
	rrotate(stack_b);
	return (3);
}
