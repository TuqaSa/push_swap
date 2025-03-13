/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 00:03:17 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/13 22:16:44 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
        t_phsw  data;

	ft_init_data(&data, argc, argv, true);
	ft_sort(&data);
	ft_print_op(data.op_list);
	ft_free_data(&data);
	exit(EXIT_SUCCESS);
}
