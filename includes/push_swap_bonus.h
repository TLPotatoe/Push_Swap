/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:49:33 by tlamit            #+#    #+#             */
/*   Updated: 2026/01/13 15:36:43 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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
int			ft_strcmp(const char *s1, const char *s2);

int			check_stack_status(t_stack *stack);
void		free_to_exit(int status, t_stack *stack_a, t_stack *stack_b);

int			push_bonus(t_stack *stack_from, t_stack *stack_to);
int			swap_bonus(t_stack *stack);
int			swap_ss_bonus(t_stack *stack_a, t_stack *stack_b);
int			rotate_bonus(t_stack *stack);
int			rotate_both_bonus(t_stack *stack_a, t_stack *stack_b);
int			r_rotate_bonus(t_stack *stack);
int			r_rotate_both_bonus(t_stack *stack_a, t_stack *stack_b);

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
