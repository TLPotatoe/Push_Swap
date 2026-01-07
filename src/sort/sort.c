/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:13:09 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/07 17:16:06 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_stack *stack_a, t_stack *stack_b)
{
	int *cost_list;

	cost_list = malloc(sizeof(int) * stack_a->max_len);
	sort_1(stack_a, stack_b);
	evaluate_cost(stack_a, stack_b, cost_list);
	sort_2(stack_a, stack_b, cost_list);

	free(cost_list);
}