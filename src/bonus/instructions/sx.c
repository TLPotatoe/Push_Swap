/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:37:48 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/12 15:52:57 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_bonus(t_stack *stack)
{
	if (!stack)
		return (2);
	if (stack->len < 2)
		return (2);
	stack->stack[0] ^= stack->stack[1];
	stack->stack[1] ^= stack->stack[0];
	stack->stack[0] ^= stack->stack[1];
	return (2);
}

int	swap_ss_bonus(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (2);
	swap_bonus(stack_a);
	swap_bonus(stack_b);
	return (2);
}
