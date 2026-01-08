/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:40:55 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/08 15:58:35 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack *stack)
{
	int	temp;

	if (!stack)
		return ;
	temp = stack->stack[stack->len - 1];
	slide_right(stack);
	if (stack->len > 0)
		stack->len--;
	stack->stack[0] = temp;
	if (stack->id == 1)
		ft_printf("rra\n");
	else if (stack->id == 2)
		ft_printf("rrb\n");
}

void	r_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0 || stack_b->len == 0)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
