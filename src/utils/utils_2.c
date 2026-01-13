/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:17:42 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/13 16:20:00 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, int value)
{
	int	i;
	int	end_index;

	i = 0;
	while (i <= stack->len / 2)
	{
		if (stack->stack[i] == value)
			return (i);
		end_index = (stack->len - 1) - i;
		if (stack->stack[end_index] == value)
			return (end_index);
		i++;
	}
	ft_printf("WARNING: VALUE NOT FOUND: %d\n", value);
	return (-1);
}

int	next_target(t_stack *stack_a, int origin)
{
	int	i;
	int	target_v;

	target_v = get_max(stack_a, NULL);
	if (origin > target_v)
		return (find_index(stack_a, get_min(stack_a, NULL)));
	i = 0;
	while (i <= stack_a->len)
	{
		if (stack_a->stack[i] >= origin && stack_a->stack[i] <= target_v)
			target_v = stack_a->stack[i];
		i++;
	}
	return (find_index(stack_a, target_v));
}

int	check_stack_status(t_stack *stack)
{
	int	i;
	int	j;

	if (!stack)
		return (1);
	i = 0;
	while (i < stack->max_len)
	{
		j = i + 1;
		while (j < stack->max_len)
			if (stack->stack[i] == stack->stack[j++])
				return (1);
		i++;
	}
	return (0);
}

void	free_to_exit(int status, t_stack *stack_a, t_stack *stack_b)
{
	static t_stack	*s_stack_a;
	static t_stack	*s_stack_b;

	if (stack_a)
		s_stack_a = stack_a;
	if (stack_b)
		s_stack_b = stack_b;
	if (status == -1 && s_stack_a)
	{
		free(s_stack_a->stack);
		s_stack_a->stack = NULL;
		free(s_stack_a);
		s_stack_a = NULL;
	}
	if (status == -1 && s_stack_b)
	{
		free(s_stack_b->stack);
		s_stack_b->stack = NULL;
		free(s_stack_b);
		s_stack_b = NULL;
	}
}
