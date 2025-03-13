/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:29:23 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/13 21:54:49 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_phsw *data, t_chunk *to_sort)
{
	t_stack	*stk;
	int		max;

	stk = ft_loc_stack(data, to_sort->loc);
	max = ft_chunk_max_value(data, to_sort);
	if (to_sort->loc == TOP_A)
		ft_sort_three_top_a(data, to_sort, stk, max);
	else if (to_sort->loc == BOTTOM_A)
		ft_sort_three_btm_a(data, to_sort, stk, max);
	else if (to_sort->loc == TOP_B)
		ft_sort_three_top_b(data, to_sort, stk, max);
	else if (to_sort->loc == BOTTOM_B)
		ft_sort_three_btm_b(data, to_sort, stk, max);
}

void	ft_sort_three_top_a(t_phsw *data, t_chunk *to_sort, t_stack *stk,
		int max)
{
	if (stk->stack[stk->top] == max)
	{
		ft_swap_a(data);
		ft_rotate_a(data);
		ft_swap_a(data);
		ft_rev_rotate_a(data);
	}
	else if (stk->stack[ft_next_down(stk, stk->top)] == max)
	{
		ft_rotate_a(data);
		ft_swap_a(data);
		ft_rev_rotate_a(data);
	}
	to_sort->loc = TOP_A;
	to_sort->size--;
	ft_sort_two(data, to_sort);
}

void	ft_sort_three_btm_a(t_phsw *data, t_chunk *to_sort, t_stack *stk,
		int max)
{
	ft_rev_rotate_a(data);
	ft_rev_rotate_a(data);
	if (stk->stack[stk->top] == max)
	{
		ft_swap_a(data);
		ft_rev_rotate_a(data);
	}
	else if (stk->stack[ft_next_down(stk, stk->top)] == max)
		ft_rev_rotate_a(data);
	else
	{
		ft_push_b(data);
		ft_rev_rotate_a(data);
		ft_swap_a(data);
		ft_push_a(data);
	}
	to_sort->loc = TOP_A;
	to_sort->size--;
	ft_sort_two(data, to_sort);
}

void	ft_sort_three_top_b(t_phsw *data, t_chunk *to_sort, t_stack *stk,
		int max)
{
	ft_push_a(data);
	if (stk->stack[stk->top] == max)
	{
		ft_push_a(data);
		ft_swap_a(data);
	}
	else if (stk->stack[ft_next_down(stk, stk->top)] == max)
	{
		ft_swap_b(data);
		ft_push_a(data);
		ft_swap_a(data);
	}
	else
		ft_push_a(data);
	ft_push_a(data);
	to_sort->loc = TOP_A;
	to_sort->size--;
	ft_sort_two(data, to_sort);
}

void	ft_sort_three_btm_b(t_phsw *data, t_chunk *to_sort, t_stack *stk,
		int max)
{
	ft_rev_rotate_b(data);
	ft_rev_rotate_b(data);
	if (stk->stack[stk->top] == max)
	{
		ft_push_a(data);
		ft_rev_rotate_b(data);
	}
	else if (stk->stack[ft_next_down(stk, stk->top)] == max)
	{
		ft_swap_b(data);
		ft_push_a(data);
		ft_rev_rotate_b(data);
	}
	else
	{
		ft_rev_rotate_b(data);
		ft_push_a(data);
	}
	to_sort->loc = TOP_B;
	to_sort->size--;
	ft_sort_two(data, to_sort);
}
