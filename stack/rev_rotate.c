/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:10:06 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/09 22:09:50 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_rev_rotate(t_stack *stk)
{
	if (ft_is_fill(stk))
	{
		stk->top = stk->bottom;
		stk->bottom = ft_next_up(stk, stk->bottom);
	}
	else
	{
		stk->top = ft_next_up(stk, stk->top);
		stk->stack[stk->top] = stk->stack[stk->bottom];
		stk->stack[stk->bottom] = 0;
		stk->bottom = ft_next_up(stk, stk->bottom);
	}
}

void	ft_rev_rotate_a(t_phsw *data)
{
	ft_rev_rotate(&data->a);
	if (data->write_mode)
		ft_save_op(data, rra);
}

void	ft_rev_rotate_b(t_phsw *data)
{
	ft_rev_rotate(&data->b);
	if (data->write_mode)
		ft_save_op(data, rrb);
}

void	ft_rev_rotate_ab(t_phsw *data)
{
	ft_rev_rotate(&data->a);
	ft_rev_rotate(&data->b);
	if (data->write_mode)
		ft_save_op(data, rrr);
}
