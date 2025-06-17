/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:11:35 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/15 16:19:00 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

int	ft_isvaild(char *str, int *is_neg)
{
	int	len;

	if (!str || !*str)
		return (0);
	len = 0;
	if (ft_issign(str[len]))
	{
		*is_neg = (str[len] == '-');
		len++;
	}
	while (str[len])
	{
		if (!ft_isdigit(str[len]))
			return (0);
		len++;
	}
	if (*is_neg || ft_issign(str[0]))
		return (len - 1);
	else
		return (len);
}

bool	ft_in_range(char *str)
{
	int	j;
	int	len;
	int	is_neg;

	j = 0;
	while (str[j])
	{
		is_neg = 0;
		len = ft_isvaild(str, &is_neg);
		if (len > 10 || len == 0)
			return (0);
		if (len == 10)
		{
			if (is_neg && (ft_strncmp(str + ft_strlen(str) - 10, "2147483648",
						10) > 0))
				return (0);
			if (!is_neg && (ft_strncmp(str + ft_strlen(str) - 10, "2147483647",
						10) > 0))
				return (0);
		}
		j++;
	}
	return (1);
}

void	ft_isdup(t_phsw *data, int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (num[j] == num[i])
			{
				free(num);
				error(data);
			}
			j++;
		}
		i++;
	}
}
