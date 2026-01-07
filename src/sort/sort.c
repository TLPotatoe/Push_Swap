/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:13:09 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/07 19:05:02 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_main(t_stack *stack_a, t_stack *stack_b)
{
	sort_1(stack_a, stack_b);
	cheapest(stack_a, stack_b);
	print_stack(stack_a, stack_b);
}
