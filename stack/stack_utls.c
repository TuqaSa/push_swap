/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:10:20 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/15 13:35:11 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_next_down(t_stack *stk, int index)
{
	if (ft_taken_size(stk) == 0)
		return (index);
	if (index == stk->size - 1)
		return (0);
	else
		return (index + 1);
}

int	ft_next_up(t_stack *stk, int index)
{
	if (ft_taken_size(stk) == 0)
		return (index);
	if (index == 0)
		return (stk->size - 1);
	else
		return (index - 1);
}

int	ft_get_value(t_stack *stk, int n)
{
	int	i;

	i = stk->top;
	while (--n > 0)
		i = ft_next_down(stk, i);
	return (stk->stack[i]);
}

int	ft_taken_size(t_stack *stk)
{
	if (stk->top == stk->bottom && stk->stack[stk->top] == 0)
		return (0);
	if (stk->top > stk->bottom)
		return ((stk->size - stk->top) + (stk->bottom + 1));
	else
		return (stk->bottom - stk->top + 1);
}

bool	ft_is_fill(t_stack *stk)
{
	return (ft_taken_size(stk) == stk->size);
}
