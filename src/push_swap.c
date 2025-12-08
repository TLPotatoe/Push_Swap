/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:36:58 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/28 00:37:03 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_stack_status(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len)
		if (stack[i++] == -1)
			return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_stack *stack_a;

	(void)ac;
	stack_a = parse(av);
	if (!check_stack_status(stack_a->stack, stack_a->len))
	{
		free(stack_a);
		return (1);
	}
	(void)stack_a;
}
