/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:30:52 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/08 16:44:12 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->len < 1)
		return ;
	stack_to->stack[stack_to->len + 1] = stack_from->stack[stack_from->len];
	(void)stack_to->len++;
	(void)stack_from->len--;
}