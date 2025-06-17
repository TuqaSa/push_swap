/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:05:28 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/09 22:09:29 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_swap(t_stack *stk)
{
	int	temp;

	if (stk->stack[ft_next_down(stk, stk->top)] == 0)
		return ;
	temp = stk->stack[ft_next_down(stk, stk->top)];
	stk->stack[ft_next_down(stk, stk->top)] = stk->stack[stk->top];
	stk->stack[stk->top] = temp;
}

void	ft_swap_a(t_phsw *data)
{
	ft_swap(&data->a);
	if (data->write_mode)
		ft_save_op(data, sa);
}

void	ft_swap_b(t_phsw *data)
{
	ft_swap(&data->b);
	if (data->write_mode)
		ft_save_op(data, sb);
}

void	ft_swap_ab(t_phsw *data)
{
	ft_swap(&data->a);
	ft_swap(&data->b);
	if (data->write_mode)
		ft_save_op(data, ss);
}
