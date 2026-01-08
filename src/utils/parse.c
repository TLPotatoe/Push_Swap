/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:14:35 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/08 17:31:53 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	long_atoi(const char *nptr, int *ret)
{
	int			sign;
	long int	result;
	int			len;

	sign = 1;
	result = 0;
	len = 0;
	while ((9 <= nptr[len] && nptr[len] <= 13) || nptr[len] == 32)
		(void)nptr[len++];
	if (nptr[len] == '-')
	{
		(void)nptr[len++];
		sign = -1;
	}
	while (ft_isdigit(nptr[len]))
		result = result * 10 + nptr[len++] - '0';
	*ret = result * sign;
	if (result * sign != (int)(result * sign))
		*ret = -1;
	while (nptr[len] == ' ')
		len++;
	return (len);
}

int	count_params_str(char *s)
{
	int	n;
	int	flag;

	n = 0;
	flag = 1;
	while (*s)
	{
		if (*s && *s == '-')
			s++;
		while (*s && ft_isdigit(*s))
		{
			if (flag)
				n++;
			flag = 0;
			s++;
		}
		if ((*s && *s != ' ') || (*(s - 1) == '-'))
			return (-1);
		while (*s && !ft_isdigit(*s) && *s != '-')
		{
			flag = 1;
			s++;
		}
	}
	return (n);
}

int	get_n_params(char **av)
{
	int	i;
	int	n;
	int	temp;

	if (!av)
		return (-1);
	i = 1;
	n = 0;
	while (av[i])
	{
		temp = count_params_str(av[i]);
		if (temp == -1)
			return (-1);
		n += temp;
		i++;
	}
	return (n);
}

t_stack	*parse(char **av)
{
	int		n;
	int		i;
	int		len;
	t_stack	*stack_a;

	n = get_n_params(av);
	if (n < 1)
		return (NULL);
	stack_a = new_stack(n);
	if (!stack_a)
		return (NULL);
	stack_a->id = 1;
	i = 0;
	len = 0;
	while (i < n)
	{
		if (*(av[1] + len) != 0)
			len += long_atoi(av[1] + len, &stack_a->stack[i++]);
		else
			len++;
	}
	return (stack_a); 
}
