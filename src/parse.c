/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:14:35 by tlamit            #+#    #+#             */
/*   Updated: 2025/11/25 18:54:43 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*ft_strcharset(char *s1, char *charset)
{
	int	i;

	while (*s1)
	{
		i = 0;
		while (charset[i])
		{
			if (*s1 == charset[i])
				return (s1);
		}
	}
	return (NULL);
}

long int	long_atoi(const char *nptr)
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
		while (*s && (*s == '-' || ft_isdigit(*s)))
		{
			if (flag)
			{
				flag = 0;
				n++;
			}
			s++;
		}
		while (*s && (*s == ' '))
		{
			flag = 1;
			s++;
		}
		if (*s && !ft_isdigit(*s) && !(*s == ' ' || *s == '-'))
			return (-1);
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
	int	i;

	(void)ac;
	i = 0;
	ft_printf("%d", get_n_params(av));
	return (NULL);
}
