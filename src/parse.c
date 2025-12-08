/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:14:35 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/08 14:06:52 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	long_atoi(const char *nptr)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		result = result * 10 + *nptr++ - '0';
	return (result * sign);
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
		if (*s && *s != ' ')
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

t_stack	*parse(int ac, char **av)
{
	int		n;
	int		i;
	int		len;
	t_stack	*stack_a;

	n = get_n_params(av);
	if (!n && n == -1)
		return (NULL);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->stack = malloc(sizeof(int) * n);
	i = 0;
	len = 0;
	while (i < n)
	{
	}
	return (NULL);
	(void)long_atoi;
}
