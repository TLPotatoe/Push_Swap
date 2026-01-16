/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:36:58 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/16 18:48:50 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parse(ac, av);
	if (stack_a)
		free_to_exit(0, stack_a, NULL);
	if (check_stack_status(stack_a))
	{
		write(2, "Error\n", 6);
		free_to_exit(-1, NULL, NULL);
		return (1);
	}
	stack_b = new_stack(stack_a->max_len);
	if (!stack_b)
	{
		free_to_exit(-1, NULL, NULL);
		return (1);
	}
	stack_b->len = 0;
	stack_b->id = 2;
	free_to_exit(0, NULL, stack_b);
	sort_main(stack_a, stack_b);
	free_to_exit(-1, NULL, NULL);
}
