/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:14:35 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/13 17:35:29 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_atoi(const char *nptr, int *ret)
{
	int	sign;
	int	len;

	sign = 1;
	len = 0;
	*ret = 0;
	while ((9 <= nptr[len] && nptr[len] <= 13) || nptr[len] == 32)
		(void)nptr[len++];
	if (nptr[len] == '-')
	{
		(void)nptr[len++];
		sign = -1;
	}
	else if (nptr[len] == '+')
		(void)nptr[len++];
	while (ft_isdigit(nptr[len]))
		*ret = *ret * 10 + nptr[len++] - '0';
	*ret = *ret * sign;
	while (nptr[len] == ' ')
		len++;
	return (len);
}

static int	ps_atoll(const char *nptr, long long int *ret)
{
	int	sign;
	int	len;

	sign = 1;
	len = 0;
	*ret = 0;
	while ((9 <= nptr[len] && nptr[len] <= 13) || nptr[len] == 32)
		(void)nptr[len++];
	if (nptr[len] == '-')
	{
		(void)nptr[len++];
		sign = -1;
	}
	else if (nptr[len] == '+')
		(void)nptr[len++];
	while (ft_isdigit(nptr[len]))
		*ret = *ret * 10 + nptr[len++] - '0';
	*ret = *ret * sign;
	while (nptr[len] == ' ')
		len++;
	return (len);
}

static int	null_check(int ac, char **av)
{
	int	i;
	int	len;
	int	flag;

	i = 1;
	while (i < ac)
	{
		len = 0;
		while ((av[i])[len])
			len++;
		if (!len)
			return (1);
		len = 0;
		flag = 0;
		while ((av[i])[len])
			if (ft_isdigit((av[i])[len++]))
				flag = 1;
		if (!flag)
			return (1);
		i++;
	}
	return (0);
}

static int	check_long(char **av)
{
	long long int	j;
	int				i;
	int				len;

	i = 0;
	j = 0;
	len = 0;
	while (i < get_n_params(av))
	{
		if (*(av[1] + len) != 0)
		{
			len += ps_atoll(av[1] + len, &j);
			i++;
			if (j != (int)j)
				return (1);
		}
		else
			len++;
	}
	return (0);
}

t_stack	*parse(int ac, char **av)
{
	int		n;
	int		i;
	int		len;
	t_stack	*stack_a;

	if (null_check(ac, av) || check_long(av))
		return (NULL);
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
			len += ps_atoi(av[1] + len, &stack_a->stack[i++]);
		else
			len++;
	}
	return (stack_a);
}
