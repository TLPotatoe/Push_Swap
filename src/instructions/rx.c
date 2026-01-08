/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:00:56 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/08 19:51:56 by tlamit           ###   ########.fr       */
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

void	rotate(t_stack *stack)
{
	local_rotate(stack);
	if (stack->id == 1)
		ft_printf("ra\n");
	else if (stack->id == 2)
		ft_printf("rb\n");
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0 || stack_b->len == 0)
		return ;
	local_rotate(stack_a);
	local_rotate(stack_b);
	ft_printf("rr\n");
}
