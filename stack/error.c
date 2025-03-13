/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:55:56 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/13 17:53:25 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_phsw *data)
{
	ft_free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	ft_free_data(t_phsw *data)
{
	if (data->a.stack)
		free(data->a.stack);
	if (data->b.stack)
		free(data->b.stack);
	if (data->op_list)
		ft_lstclear(&data->op_list, NULL);
}
