/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:17:42 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/13 17:36:48 by tlamit           ###   ########.fr       */
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

static int	count_params_str(char *s)
{
	int	n;
	int	flag;

	n = 0;
	flag = 1;
	while (*s)
	{
		if (*s && (*s == '-' || *s == '+'))
			s++;
		while (*s && ft_isdigit(*s))
		{
			if (flag)
				n++;
			flag = 0;
			s++;
		}
		if ((*s && *s != ' ') || (*(s - 1) == '-' || *(s - 1) == '+'))
			return (-1);
		while (*s && !ft_isdigit(*s) && *s != '-')
		{
			flag = 1;
			s++;
		}
	}
	return (n);
}

int	get_n_params(char **av)
{
	int	i;
	int	n;
	int	temp;

	if (!av)
		return (-1);
	i = 1;
	n = 0;
	while (av[i])
	{
		temp = count_params_str(av[i]);
		if (temp == -1)
			return (-1);
		n += temp;
		i++;
	}
	return (n);
}
