/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:40:32 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/08 20:26:06 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_in_struct(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] == value)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcharset(char *s1, char *charset)
{
	int	i;

	while (*s1)
	{
		i = 0;
		while (charset[i])
			if (*s1 == charset[i])
				return (s1);
	}
	return (NULL);
}

t_stack	*new_stack(int len)
{
	int		i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->stack = malloc(sizeof(int) * len);
	if (!stack->stack)
	{
		free(stack);
		return (NULL);
	}
	stack->max_len = len;
	stack->len = len;
	i = 0;
	while (i < stack->max_len)
	{
		stack->stack[i] = -i;
		i++;
	}
	return (stack);
}

int	get_max(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_a;
	int	max_b;

	i = 0;
	max_a = stack_a->stack[0];
	while (i < stack_a->len)
	{
		if (stack_a->stack[i] > max_a)
			max_a = stack_a->stack[i];
		i++;
	}
	if (!stack_b)
		return (max_a);
	max_b = stack_b->stack[0];
	i = 0;
	while (i < stack_b->len)
	{
		if (stack_b->stack[i] > max_b)
			max_b = stack_b->stack[i];
		i++;
	}
	if (max_a > max_b)
		return (max_a);
	return (max_b);
}

int	get_min(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_a;
	int	min_b;

	i = 0;
	min_a = stack_a->stack[0];
	while (i < stack_a->len)
	{
		if (stack_a->stack[i] < min_a)
			min_a = stack_a->stack[i];
		i++;
	}
	if (!stack_b)
		return (min_a);
	i = 0;
	min_b = stack_b->stack[0];
	while (i < stack_b->len)
	{
		if (stack_b->stack[i] < min_b)
			min_b = stack_b->stack[i];
		i++;
	}
	if (min_a < min_b)
		return (min_a);
	return (min_b);
}

static void print_padded_int(int value, int width)
{
    int     len;
    long    temp; // long to handle INT_MIN safely

    len = 0;
    temp = value;
    if (value <= 0) // Count 1 for '0' or '-' sign
        len++;
    while (temp != 0)
    {
        temp /= 10;
        if (temp != 0 || value > 0) // Avoid double counting for 0
            len++;
    }
    // Print spaces (padding)
    while (len < width)
    {
        ft_printf(" ");
        len++;
    }
    ft_printf("%d", value);
}

void    print_stack(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int bar;

    i = 0;
    ft_printf("\nPRINT\n--------------\n");
    if (stack_a->len < 1)
        ft_printf("StackA Empty %d\n", stack_a->len);
    while (i < stack_a->len)
    {
        ft_printf("A I:");
        print_padded_int(i, 3);          // Align index on 3 chars
        ft_printf(" LEN:");
        print_padded_int(stack_a->len, 3); // Align len on 3 chars
        ft_printf(" >| ");
        print_padded_int(stack_a->stack[i], 6); // Align val on 6 chars
        ft_printf(" ");

        bar = 0;
        // Limit bars to 50 to avoid spamming terminal
        while (bar < stack_a->stack[i] / 2 && bar < 50)
        {
            ft_printf("▮");
            bar++;
        }
        ft_printf("\n");
        i++;
    }

    if (stack_b)
    {
        ft_printf("--------------\n");
        i = 0;
        if (stack_b->len < 1)
            ft_printf("StackB Empty %d\n", stack_b->len);
        while (i < stack_b->len)
        {
            ft_printf("B I:");
            print_padded_int(i, 3);
            ft_printf(" LEN:");
            print_padded_int(stack_b->len, 3);
            ft_printf(" >| ");
            print_padded_int(stack_b->stack[i], 6);
            ft_printf(" ");

            bar = 0;
            while (bar < stack_b->stack[i] / 2 && bar < 50)
            {
                ft_printf("▮");
                bar++;
            }
            ft_printf("\n");
            i++;
        }
    }
    else
        ft_printf("No Stack B\n");
    ft_printf("------------------\n");
}