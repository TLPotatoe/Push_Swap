/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:40:32 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/07 16:51:18 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcharset(char *s1, char *charset)
{
	int	i;

	while (*s1)
	{
		i = 0;
		while (charset[i])
			if (*s1 == charset[i])
				return (s1);
	}
	return (NULL);
}

t_stack	*new_stack(int len)
{
	int		i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->stack = malloc(sizeof(int) * len);
	if (!stack->stack)
	{
		free(stack);
		return (NULL);
	}
	stack->max_len = len;
	stack->len = len;
	i = 0;
	while (i < stack->max_len)
	{
		stack->stack[i] = -i;
		i++;
	}
	return (stack);
}

int	get_max(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_a;
	int	max_b;

	i = 0;
	max_a = stack_a->stack[0];
	while (i < stack_a->len)
	{
		if (stack_a->stack[i] > max_a)
			max_a = stack_a->stack[i];
		i++;
	}
	if (!stack_b)
		return (max_a);
	max_b = stack_b->stack[0];
	i = 0;
	while (i < stack_b->len)
	{
		if (stack_b->stack[i] > max_b)
			max_b = stack_b->stack[i];
		i++;
	}
	if (max_a > max_b)
		return (max_a);
	return (max_b);
}

int	get_min(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_a;
	int	min_b;

	i = 0;
	min_a = stack_a->stack[0];
	while (i < stack_a->len)
	{
		if (stack_a->stack[i] < min_a)
			min_a = stack_a->stack[i];
		i++;
	}
	if (!stack_b)
		return (min_a);
	i = 0;
	min_b = stack_b->stack[0];
	while (i < stack_b->len)
	{
		if (stack_b->stack[i] < min_b)
			min_b = stack_b->stack[i];
		i++;
	}
	if (min_a < min_b)
		return (min_a);
	return (min_b);
}

int	value_in_struct(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	bar;

	i = 0;
	ft_printf("\n\nPRINT\n--------------\n");
	if (stack_a->len < 1)
		ft_printf("StackA Empty %d\n", stack_a->len);
	while (i < stack_a->len)
	{
		ft_printf("A I:%d LEN %d >| %d ", i, stack_a->len, stack_a->stack[i]);
		bar = 0;
		while (bar < stack_a->stack[i])
		{
			ft_printf("▮");
			bar++;
		}
		ft_printf("\n");
		(void)i++;
	}
	if (stack_b)
	{
		ft_printf("--------------\n");
		i = 0;
		if (stack_b->len < 1)
			ft_printf("StackB Empty %d\n", stack_b->len);
		while (i < stack_b->len)
		{
			ft_printf("B I:%d LEN %d >| %d ", i, stack_b->len,
				stack_b->stack[i]);
			bar = 0;
			while (bar < stack_b->stack[i])
			{
				ft_printf("▮");
				bar++;
			}
			ft_printf("\n");
			(void)i++;
		}
	}
	else
		ft_printf("No Stack B\n");
	ft_printf("------------------\n");
}
