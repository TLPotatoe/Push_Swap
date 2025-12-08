/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:40:32 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/08 14:25:56 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
