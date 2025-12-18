/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:49:33 by tlamit            #+#    #+#             */
/*   Updated: 2025/12/18 17:59:44 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*stack;
	int		max_len;
	int		len;
	char	id;
}			t_stack;

t_stack		*parse(char **av);
t_stack		*new_stack(int len);

char		*ft_strcharset(char *s1, char *charset);

void		push(t_stack *stack_from, t_stack *stack_to);
void		swap(t_stack *stack);
void		swap_ss(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		r_rotate(t_stack *stack);
void		r_rotate_both(t_stack *stack_a, t_stack *stack_b);


void		slide_left(t_stack *stack);
void		slide_right(t_stack *stack);

void		free_to_exit(int status, t_stack *stack_a, t_stack *stack_b);

void		print_stack(t_stack *stack_a, t_stack *stack_b);

#endif
