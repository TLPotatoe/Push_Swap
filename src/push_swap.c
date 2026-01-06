/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:36:58 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/06 16:07:51 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack_status(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->max_len)
		if (stack->stack[i++] == -1)
			return (1);
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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)ac;
	stack_a = parse(av);
	if (!stack_a)
		return (1);
	free_to_exit(0, stack_a, NULL);
	if (check_stack_status(stack_a))
	{
		free_to_exit(-1, NULL, NULL);
		return (1);
	}
	stack_b = new_stack(stack_a->max_len);
	if (!stack_b)
	{
		free_to_exit(-1, NULL, NULL);
		return (1);
	}
	stack_b->len = 0;
	stack_b->id = 2;
	free_to_exit(0, NULL, stack_b);
	sort_1(stack_a, stack_b);
	free_to_exit(-1, NULL, NULL);
}
