/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:30:52 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/12 15:52:26 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_bonus(t_stack *stack_from, t_stack *stack_to)
{
	if (!stack_from || !stack_to)
		return (2);
	if (stack_from->len == 0 || stack_to->len == stack_to->max_len)
		return (2);
	slide_right(stack_to);
	stack_to->stack[0] = stack_from->stack[0];
	slide_left(stack_from);
	return (2);
}
