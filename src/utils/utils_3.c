/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:38:27 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/14 14:01:44 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
