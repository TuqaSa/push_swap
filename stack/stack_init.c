/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:36:44 by tsaeed            #+#    #+#             */
/*   Updated: 2025/02/25 22:57:54 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_stack(t_phsw *data, t_stack *stk, char **argv, int size)
{
	int	i;
	int	*num;

	num = malloc(sizeof(int) * size);
	if (!num)
		error(data);
	i = 0;
	while (argv[i])
	{
		if (!ft_in_range(argv[i]))
			error(data);
		num[i] = ft_atoi(argv[i]);
		i++;
	}
	ft_isdup(data, num, size);
	ft_ranking(num, stk->stack, size);
	stk->bottom = size - 1;
	free(num);
}

void	ft_init_data(t_phsw *data, int argc, char **argv, bool write_mode)
{
	--argc;
	ft_init_stack(data, &data->a, argc);
	ft_init_stack(data, &data->b, argc);
	ft_fill_stack(data, &data->a, ++argv, argc);
	data->write_mode = write_mode;
	data->op_list = NULL;
}

void	ft_init_stack(t_phsw *data, t_stack *stk, int size)
{
	stk->stack = malloc(sizeof(int) * size);
	if (!stk->stack)
		error(data);
	stk->top = 0;
	stk->bottom = 0;
	stk->size = size;
	ft_memset(stk->stack, 0, sizeof(int) * size);
}

void	ft_ranking(int *num, int *rank, int size)
{
	int i;
	int j;
	int count_smaller;

	i = 0;
	while (i < size)
	{
		j = 0;
		count_smaller = 0;
		while (j < size)
			if (num[j++] <= num[i])
				count_smaller++;
		rank[i] = count_smaller;
		i++;
	}
}