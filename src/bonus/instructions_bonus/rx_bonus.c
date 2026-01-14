/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:00:56 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/14 14:03:36 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	local_rotate(t_stack *stack)
{
	int	temp;

	temp = stack->stack[0];
	slide_left(stack);
	stack->stack[stack->len] = temp;
	stack->len++;
}

int	rotate_bonus(t_stack *stack)
{
	local_rotate(stack);
	return (2);
}

int	rotate_both_bonus(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0 || stack_b->len == 0)
		return (2);
	local_rotate(stack_a);
	local_rotate(stack_b);
	return (2);
}
