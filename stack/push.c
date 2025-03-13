/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:06:18 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/09 22:10:41 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_push(t_stack *src, t_stack *dest)
{
	int	index;

	if (ft_is_fill(dest))
		return ;
	index = ft_next_up(dest, dest->top);
	dest->stack[index] = src->stack[src->top];
	dest->top = index;
	src->stack[src->top] = 0;
	src->top = ft_next_down(src, src->top);
}

void	ft_push_b(t_phsw *data)
{
	ft_push(&data->a, &data->b);
	if (data->write_mode)
		ft_save_op(data, pb);
}

void	ft_push_a(t_phsw *data)
{
	ft_push(&data->b, &data->a);
	if (data->write_mode)
		ft_save_op(data, pa);
}
