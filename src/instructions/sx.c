/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:37:48 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/05 19:24:05 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->len < 2)
		return ;
	stack->stack[0] ^= stack->stack[1];
	stack->stack[1] ^= stack->stack[0];
	stack->stack[0] ^= stack->stack[1];
	if (stack->id == 1)
		ft_printf("sa\n");
	else if (stack->id == 2)
		ft_printf("sb\n");
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
