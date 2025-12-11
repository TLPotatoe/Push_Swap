/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:30:52 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/11 15:24:19 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from2, t_stack *stack_to2)
{
	int		i;
	t_stack	*stack_from;
	t_stack	*stack_to;
	int		stack[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
				17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
	stack_from->stack = stack;
	stack_from->len = 29;
	if (stack_from->len < 1)
		return ;
	i = 0;
	while (i < stack_from->len)
		ft_printf("VAL %d\n", stack_from->stack[i++]);
	i = 0;
	// while (i < stack_from->len)
}
