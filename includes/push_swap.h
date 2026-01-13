/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:49:33 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/13 17:37:46 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647

typedef struct s_stack
{
	int		*stack;
	int		max_len;
	int		len;
	char	id;
}			t_stack;

t_stack		*parse(int ac, char **av);
t_stack		*new_stack(int len);

char		*ft_strcharset(char *s1, char *charset);

int			get_n_params(char **av);
int			check_stack_status(t_stack *stack);
void		free_to_exit(int status, t_stack *stack_a, t_stack *stack_b);

void		push(t_stack *stack_from, t_stack *stack_to);
void		swap(t_stack *stack);
void		swap_ss(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		r_rotate(t_stack *stack);
void		r_rotate_both(t_stack *stack_a, t_stack *stack_b);

void		slide_left(t_stack *stack);
void		slide_right(t_stack *stack);

int			cost_b(t_stack *stack_b, int i);
int			cost_top(t_stack *stack, int itarget);
int			cost_a(t_stack *stack_a, t_stack *stack_b, int i);
int			total_cost(t_stack *stack_a, t_stack *stack_b, int i);

int			find_index(t_stack *stack, int value);
int			next_target(t_stack *stack_a, int origin);
int			value_in_struct(t_stack *stack, int value);
int			get_max(t_stack *stack_a, t_stack *stack_b);
int			get_min(t_stack *stack_a, t_stack *stack_b);
void		cheapest(t_stack *stack_a, t_stack *stack_b);

void		sort_1(t_stack *stack_a, t_stack *stack_b);
void		sort_main(t_stack *stack_a, t_stack *stack_b);

#endif
