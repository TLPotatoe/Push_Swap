/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:40:32 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/12 17:41:39 by tlamit           ###   ########.fr       */
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

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	ft_printf("\n\nPRINT\n------------------\n");
	if (stack_a->len < 1)
		ft_printf("StackA Empty %d\n", stack_a->len);
	while (i < stack_a->len)
	{
		ft_printf("STACK A %d ->| %d LEN %d\n", i, stack_a->stack[i], stack_a->len);
		(void)i++;
	}
	if (stack_b)
	{
		ft_printf("------------------\n");
		i = 0;
		if (stack_b->len < 1)
			ft_printf("StackB Empty %d\n", stack_b->len);
		while (i < stack_b->len)
		{
			ft_printf("STACK B %d ->| %d LEN %d\n", i, stack_b->stack[i], stack_b->len);
			(void)i++;
		}
	}
	else
		ft_printf("No Stack B\n");
	ft_printf("------------------\n");
}
