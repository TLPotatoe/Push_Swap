/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:37:48 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/16 18:12:24 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->len < 1)
		return ;
	temp = stack->stack[stack->len];
	stack->stack[stack->len] = stack->stack[stack->len - 1];
	stack->stack[stack->len - 1] = temp;
}

void	swap_x(t_stack *stack_a)
{
	if (!stack_a)
		return ;
	swap(stack_a);
	if (stack_a->id == 1)
		ft_printf("sa\n");
	else if (stack_a->id == 2)
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
