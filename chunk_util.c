/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:35:17 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/12 01:14:09 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_postion(t_loc loc, t_stack *stk)
{
	if (loc == TOP_A || loc == TOP_B)
		return (stk->top);
	else
		return (stk->bottom);
}

t_stack	*ft_loc_stack(t_phsw *data, t_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&data->a);
	else
		return (&data->b);
}

int	ft_chunk_value(t_phsw *data, t_chunk *chunk, int n)
{
	t_loc	loc;
	t_stack	*stk;
	int		i;

	loc = chunk->loc;
	stk = ft_loc_stack(data, loc);
	if (loc == TOP_A || loc == TOP_B)
		i = stk->top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = stk->bottom;
	if (loc == TOP_A || loc == TOP_B)
		while (--n > 0)
			i = ft_next_down(stk, i);
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		while (--n > 0)
			i = ft_next_up(stk, i);
	return (stk->stack[i]);
}

int	ft_chunk_max_value(t_phsw *data, t_chunk *chunk)
{
	t_stack	*stk;
	int		size;
	int		max;
	int		i;

	stk = ft_loc_stack(data, chunk->loc);
	size = chunk->size;
	max = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = stk->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = stk->bottom;
	while (size--)
	{
		if (stk->stack[i] > max)
			max = stk->stack[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = ft_next_down(stk, i);
		else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
			i = ft_next_up(stk, i);
	}
	return (max);
}
