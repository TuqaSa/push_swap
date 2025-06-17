/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:16:56 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/12 18:24:03 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_phsw *data)
{
	int	i;
	int	rank;

	i = data->a.top;
	rank = 1;
	while (rank < data->a.size)
	{
		if (data->a.stack[i] != rank)
			return (false);
		rank++;
		i = ft_next_down(&data->a, i);
	}
	return (true);
}

void	ft_sort_three_a(t_phsw *data)
{
	int	first;
	int	second;
	int	third;

	first = ft_get_value(&data->a, 1);
	second = ft_get_value(&data->a, 2);
	third = ft_get_value(&data->a, 3);
	if (first > second && second < third && third > first)
		ft_swap_a(data);
	else if (first > second && second < third && third < first)
		ft_rotate_a(data);
	else if (first < second && second > third && third < first)
		ft_rev_rotate_a(data);
	else if (first > second && second > third && third < first)
	{
		ft_swap_a(data);
		ft_rev_rotate_a(data);
	}
	else if (first < second && second > third && third > first)
	{
		ft_swap_a(data);
		ft_rotate_a(data);
	}
}

void	ft_sort_five_a(t_phsw *data)
{
	while (ft_taken_size(&data->a) > 3)
	{
		if (ft_get_value(&data->a, 1) == 1 || ft_get_value(&data->a, 1) == 2)
			ft_push_b(data);
		else
			ft_rotate_a(data);
	}
	if (ft_get_value(&data->b, 1) < ft_get_value(&data->b, 2))
		ft_swap_b(data);
	ft_sort_three_a(data);
	ft_push_a(data);
	ft_push_a(data);
}

void	ft_sort(t_phsw *data)
{
	if (ft_is_sorted(data) || data->a.size <= 1)
		return ;
	else if (data->a.size == 3)
		ft_sort_three_a(data);
	else if (data->a.size == 5)
		ft_sort_five_a(data);
	else
		ft_chunk_sort(data);
}
