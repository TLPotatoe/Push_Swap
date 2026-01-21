/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:09:51 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/21 16:33:28 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_sorted(t_stack *stack_a)
{
	int	i;
	int	min;

	i = 0;
	min = -2147483648;
	while (i < stack_a->len)
	{
		if (stack_a->stack[i] > min)
			min = stack_a->stack[i];
		if (stack_a->stack[i] < min)
			return (0);
		i++;
	}
	return (1);
}

static int	process_input(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (!ft_strncmp(str, "pa\n", 3))
		str += push_bonus(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb\n", 3))
		str += push_bonus(stack_a, stack_b);
	else if (!ft_strncmp(str, "sa\n", 3))
		str += swap_bonus(stack_a);
	else if (!ft_strncmp(str, "sb\n", 3))
		str += swap_bonus(stack_b);
	else if (!ft_strncmp(str, "ss\n", 3))
		str += swap_ss_bonus(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra\n", 3))
		str += rotate_bonus(stack_a);
	else if (!ft_strncmp(str, "rb\n", 3))
		str += rotate_bonus(stack_b);
	else if (!ft_strncmp(str, "rra\n", 4))
		str += r_rotate_bonus(stack_a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		str += r_rotate_bonus(stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		str += r_rotate_both_bonus(stack_a, stack_b);
	else if (!ft_strncmp(str, "rr\n", 3))
		str += rotate_both_bonus(stack_a, stack_b);
	else
		return (0);
	return (*str);
}

static int	listen(t_stack *stack_a, t_stack *stack_b, int len)
{
	char	line[65536];

	while (len)
	{
		len = read(0, line, 65536);
		if (len == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (!len)
			return (0);
		line[len] = 0;
		if (process_input(stack_a, stack_b, line) == 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

static void	print_stack_status(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_b->len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parse(ac, av);
	if (check_stack_status(stack_a))
	{
		write(2, "Error\n", 6);
		free_to_exit(-1, stack_a, NULL);
		return (1);
	}
	stack_b = new_stack(stack_a->max_len);
	if (!stack_b)
	{
		free_to_exit(-1, stack_a, NULL);
		return (1);
	}
	stack_b->len = 0;
	stack_b->id = 2;
	if (!listen(stack_a, stack_b, 1))
		print_stack_status(stack_a, stack_b);
	free_to_exit(-1, stack_a, stack_b);
}
