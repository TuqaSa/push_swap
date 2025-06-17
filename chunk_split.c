/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:04:03 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/13 17:46:22 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_split_loc(t_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = BOTTOM_A;
	}
	else if (loc == BOTTOM_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOTTOM_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
	else if (loc == BOTTOM_B)
	{
		min->loc = TOP_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
}

void	ft_init_size(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	ft_set_pivots(t_loc loc, int currt_size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = currt_size / 3;
	if (loc == TOP_A || loc == BOTTOM_A)
		*pivot_1 = 2 * currt_size / 3;
	if (loc == TOP_B || loc == BOTTOM_B)
		*pivot_1 = currt_size / 2;
	if ((loc == TOP_A || loc == BOTTOM_A) && currt_size < 15)
		*pivot_1 = currt_size;
	if (loc == BOTTOM_B && currt_size < 8)
		*pivot_2 = currt_size / 2;
}

void	ft_chunk_split(t_phsw *data, t_chunk *to_split, t_split *split)
{
	int	pivot_1;
	int	pivot_2;
	int	max;
	int	next;

	ft_init_size(&split->min, &split->mid, &split->max);
	ft_set_split_loc(to_split->loc, &split->min, &split->mid, &split->max);
	ft_set_pivots(to_split->loc, to_split->size, &pivot_1, &pivot_2);
	max = ft_chunk_max_value(data, to_split);
	while (to_split->size--)
	{
		next = ft_chunk_value(data, to_split, 1);
		if (next > max - pivot_2)
		{
			split->max.size += ft_move_from_to(data, to_split->loc,
					split->max.loc);
		}
		else if (next > max - pivot_1)
			split->mid.size += ft_move_from_to(data, to_split->loc,
					split->mid.loc);
		else
			split->min.size += ft_move_from_to(data, to_split->loc,
					split->min.loc);
	}
}
