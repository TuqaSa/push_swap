/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:21:30 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/09 20:05:16 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "Libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*stack;
	int		size;
	int		top;
	int		bottom;
}			t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	t_list	*op_list;
	bool	write_mode;
}			t_phsw;

typedef enum e_op
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	null_op
}			t_op;

int			ft_issign(char c);
int			ft_isvaild(char *str, int *is_neg);
bool		ft_in_range(char *str);
void		ft_isdup(t_phsw *data, int *num, int size);
void		ft_ranking(int *num, int *rank, int size);
void		ft_fill_stack(t_phsw *data, t_stack *stk, char **argv, int size);
void		ft_init_data(t_phsw *data, int argc, char **argv, bool write_mode);
void		error(t_phsw *data);
void		ft_free_data(t_phsw *data);
void		ft_init_stack(t_phsw *data, t_stack *stk, int size);
int			ft_taken_size(t_stack *stk);
int			ft_next_down(t_stack *stk, int index);
int			ft_next_up(t_stack *stk, int index);
int			ft_get_value(t_stack *stk, int n);
int			ft_taken_size(t_stack *stk);
bool		ft_is_fill(t_stack *stk);
bool		ft_is_sorted(t_phsw *data);

void		ft_save_op(t_phsw *data, t_op op);
t_op		ft_get_op(t_list *op);
void		ft_print_op(t_list *head);
const char	*ft_op_to_string(t_op op);

void		ft_swap(t_stack *stk);
void		ft_swap_a(t_phsw *data);
void		ft_swap_b(t_phsw *data);
void		ft_swap_ab(t_phsw *data);
void		ft_push(t_stack *stka, t_stack *stkb);
void		ft_push_b(t_phsw *data);
void		ft_push_a(t_phsw *data);
void		ft_rotate(t_stack *stk);
void		ft_rotate_a(t_phsw *data);
void		ft_rotate_b(t_phsw *data);
void		ft_rotate_ab(t_phsw *data);

void		ft_rev_rotate(t_stack *stk);
void		ft_rev_rotate_a(t_phsw *data);
void		ft_rev_rotate_b(t_phsw *data);
void		ft_rev_rotate_ab(t_phsw *data);

#endif
