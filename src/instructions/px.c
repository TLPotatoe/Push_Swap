/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:30:52 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/12 18:04:45 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	slide_left(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->len < 0)
		return ;
	while (i < stack->len - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		(void)i++;
	}
	if (stack->len > 0)
		(void)stack->len--;
}

static void	slide_right(t_stack *stack)
{
	int	i;

	if (stack->len == stack->max_len)
		return ;
	i = stack->len;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		(void)i--;
	}
	if (stack->len < stack->max_len)
		(void)stack->len++;
}

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
		ft_printf("pa");
	if (stack_to->id == 2)
		ft_printf("pb");
}
