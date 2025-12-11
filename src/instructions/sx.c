/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:37:48 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/11 14:51:19 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->len < 1)
		return ;
	temp = stack->stack[stack->len];
	stack->stack[stack->len] = stack->stack[stack->len - 1];
	stack->stack[stack->len - 1] = temp;
}
