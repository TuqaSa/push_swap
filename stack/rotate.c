/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:07:00 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/09 22:10:08 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_rotate(t_stack *stk)
{
	if (ft_is_fill(stk))
	{
		stk->bottom = stk->top;
		stk->top = ft_next_down(stk, stk->top);
	}
	else
	{
		stk->bottom = ft_next_down(stk, stk->bottom);
		stk->stack[stk->bottom] = stk->stack[stk->top];
		stk->stack[stk->top] = 0;
		stk->top = ft_next_down(stk, stk->top);
	}
}

void	ft_rotate_a(t_phsw *data)
{
	ft_rotate(&data->a);
	if (data->write_mode)
		ft_save_op(data, ra);
}

void	ft_rotate_b(t_phsw *data)
{
	ft_rotate(&data->b);
	if (data->write_mode)
		ft_save_op(data, rb);
}

void	ft_rotate_ab(t_phsw *data)
{
	ft_rotate(&data->a);
	ft_rotate(&data->b);
	if (data->write_mode)
		ft_save_op(data, rr);
}
