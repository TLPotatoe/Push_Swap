/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:40:55 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/18 18:29:01 by tlamit           ###   ########.fr       */
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
	stack->stack[0] = temp;
	// stack->len++;
	if (stack->id == 1)
		ft_printf("ra\n");
	else if (stack->id == 2)
		ft_printf("rb\n");
}

void	r_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0 || stack_b->len == 0)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
