/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:17:42 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/08 17:20:18 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_index(t_stack *stack, int value)
{
    int i;
    int end_index;

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
