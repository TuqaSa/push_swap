/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:38:06 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/12 01:49:44 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_from_top_a(t_phsw *data, t_loc to)
{
	if (to == TOP_B)
		ft_push_b(data);
	else if (to == BOTTOM_A)
		ft_rotate_a(data);
	else if (to == BOTTOM_B)
	{
		ft_push_b(data);
		ft_rotate_b(data);
	}
}

void	ft_move_from_top_b(t_phsw *data, t_loc to)
{
	if (to == TOP_A)
		ft_push_a(data);
	else if (to == BOTTOM_B)
		ft_rotate_b(data);
	else if (to == BOTTOM_A)
	{
		ft_push_a(data);
		ft_rotate_a(data);
	}
}

void	ft_move_from_bottom_a(t_phsw *data, t_loc to)
{
	if (to == TOP_A)
		ft_rev_rotate_a(data);
	else if (to == TOP_B)
	{
		ft_rev_rotate_a(data);
		ft_push_b(data);
	}
	else if (to == BOTTOM_B)
	{
		ft_rev_rotate_a(data);
		ft_push_b(data);
		ft_rotate_b(data);
	}
}

void	ft_move_from_bottom_b(t_phsw *data, t_loc to)
{
	if (to == TOP_B)
		ft_rev_rotate_b(data);
	else if (to == TOP_A)
	{
		ft_rev_rotate_b(data);
		ft_push_a(data);
	}
	else if (to == BOTTOM_A)
	{
		ft_rev_rotate_b(data);
		ft_push_a(data);
		ft_rotate_a(data);
	}
}

int	ft_move_from_to(t_phsw *data, t_loc from, t_loc to)
{
	if (from == TOP_A)
		ft_move_from_top_a(data, to);
	else if (from == TOP_B)
		ft_move_from_top_b(data, to);
	else if (from == BOTTOM_A)
		ft_move_from_bottom_a(data, to);
	else if (from == BOTTOM_B)
		ft_move_from_bottom_b(data, to);
	return (1);
}
