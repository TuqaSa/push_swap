/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprations_utls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:55:24 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/15 14:10:49 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_save_op(t_phsw *data, t_op op)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)op);
	if (!new)
		error(data);
	ft_lstadd_back(&data->op_list, new);
}

t_op	ft_get_op(t_list *op)
{
	return ((t_op)(uintptr_t)op->content);
}

void	ft_print_op(t_list *head)
{
	t_list	*reader;

	reader = head;
	while (reader)
	{
		ft_putstr_fd((char *)ft_op_to_string(ft_get_op(reader)), 1);
		ft_putstr_fd("\n", 1);
		reader = reader->next;
	}
}

const char	*ft_op_to_string(t_op op)
{
	static const char	*op_str[12];

	op_str[0] = "sa";
	op_str[1] = "sb";
	op_str[2] = "ss";
	op_str[3] = "pa";
	op_str[4] = "pb";
	op_str[5] = "ra";
	op_str[6] = "rb";
	op_str[7] = "rr";
	op_str[8] = "rra";
	op_str[9] = "rrb";
	op_str[10] = "rrr";
	op_str[11] = "null_op";
	return (op_str[op]);
}
