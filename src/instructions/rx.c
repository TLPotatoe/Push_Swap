/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:00:56 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/06 16:06:59 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	temp;

	if (!stack)
		return ;
	temp = stack->stack[0];
	slide_left(stack);
	stack->stack[stack->len] = temp;
	stack->len++;
	if (stack->id == 1)
		ft_printf("ra\n");
	else if (stack->id == 2)
		ft_printf("rb\n");
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0 || stack_b->len == 0)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
