/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:39:52 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/13 21:42:31 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_one(t_phsw *data, t_chunk *to_sort)
{
	t_loc	loc;

	loc = to_sort->loc;
	if (loc == BOTTOM_A || loc == BOTTOM_B || loc == TOP_B)
		ft_move_from_to(data, loc, TOP_A);
	to_sort->size -= 1;
}

void	ft_sort_two(t_phsw *data, t_chunk *to_sort)
{
	t_loc	loc;

	loc = to_sort->loc;
	if (loc == BOTTOM_A || loc == BOTTOM_B || loc == TOP_B)
	{
		ft_move_from_to(data, loc, TOP_A);
		ft_move_from_to(data, loc, TOP_A);
	}
	if (ft_get_value(&data->a, 1) > ft_get_value(&data->a, 2))
		ft_swap_a(data);
	to_sort->size -= 2;
}

void	ft_rec_chunk_sort(t_phsw *data, t_chunk *to_sort)
{
	t_split	split;

	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			ft_sort_three(data, to_sort);
		else if (to_sort->size == 2)
			ft_sort_two(data, to_sort);
		else if (to_sort->size == 1)
			ft_sort_one(data, to_sort);
		return ;
	}
	ft_chunk_split(data, to_sort, &split);
	ft_rec_chunk_sort(data, &split.max);
	ft_rec_chunk_sort(data, &split.mid);
	ft_rec_chunk_sort(data, &split.min);
}

void	ft_chunk_sort(t_phsw *data)
{
	t_chunk	the_chunk;

	the_chunk.loc = TOP_A;
	the_chunk.size = data->a.size;
	ft_rec_chunk_sort(data, &the_chunk);
}
