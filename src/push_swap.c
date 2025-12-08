/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:36:58 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/08 14:25:59 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack_status(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (stack[i++] == -1)
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;

	(void)ac;
	stack_a = parse(av);
	i = 0;
	while (stack_a->len > i)
	{
		ft_printf("VAL %d\n", stack_a->stack[i++]);
	}
	if (!check_stack_status(stack_a->stack, stack_a->len))
	{
		free(stack_a);
		return (1);
	}
	(void)stack_a;
}
