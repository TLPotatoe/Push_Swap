/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:30:52 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/08 18:25:06 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	if (!stack_from || !stack_to)
		return ;
	if (stack_from->len == 0 || stack_to->len == stack_to->max_len)
		return ;
	slide_right(stack_to);
	stack_to->stack[0] = stack_from->stack[0];
	slide_left(stack_from);
	if (stack_to->id == 1)
		ft_printf("pa\n");
	if (stack_to->id == 2)
		ft_printf("pb\n");
}
