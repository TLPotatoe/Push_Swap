/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:13:09 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/07 18:45:03 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_stack *stack_a, t_stack *stack_b)
{
	int	*cost_list;

	sort_1(stack_a, stack_b);
	bring_top(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	sort_2(stack_a, stack_b, cost_list);
}
