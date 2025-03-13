/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <tsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 00:07:56 by tsaeed            #+#    #+#             */
/*   Updated: 2025/03/13 21:41:19 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include <stdint.h>

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}			t_loc;

typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}			t_chunk;
typedef struct s_split
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}			t_split;

void		ft_sort_three_a(t_phsw *data);
void		ft_sort_five_a(t_phsw *data);
void		ft_sort(t_phsw *data);
void		ft_set_split_loc(t_loc loc, t_chunk *min, t_chunk *mid,
				t_chunk *max);
void		ft_init_size(t_chunk *min, t_chunk *mid, t_chunk *max);
void		ft_chunk_split(t_phsw *data, t_chunk *to_split, t_split *split);
int			ft_postion(t_loc loc, t_stack *stk);
t_stack		*ft_loc_stack(t_phsw *data, t_loc loc);
int			ft_chunk_value(t_phsw *data, t_chunk *chunk, int n);
int			ft_chunk_max_value(t_phsw *data, t_chunk *chunk);
void		ft_set_pivots(t_loc loc, int currt_size, int *pivot_1,
				int *pivot_2);
void		ft_move_from_top_a(t_phsw *data, t_loc to);
void		ft_move_from_top_b(t_phsw *data, t_loc to);
void		ft_move_from_bottom_a(t_phsw *data, t_loc to);
void		ft_move_from_bottom_b(t_phsw *data, t_loc to);
int			ft_move_from_to(t_phsw *data, t_loc from, t_loc to);
void		ft_rec_chunk_sort(t_phsw *data, t_chunk *to_sort);
void		ft_chunk_sort(t_phsw *data);
void		ft_sort_one(t_phsw *data, t_chunk *to_sort);
void		ft_sort_two(t_phsw *data, t_chunk *to_sort);
void	ft_sort_three(t_phsw *data, t_chunk *to_sort);
void	ft_sort_three_top_a(t_phsw *data, t_chunk *to_sort, t_stack *stk,int max);
void	ft_sort_three_btm_a(t_phsw *data, t_chunk *to_sort, t_stack *stk,int max);
void	ft_sort_three_top_b(t_phsw *data, t_chunk *to_sort, t_stack *stk,int max);
void	ft_sort_three_btm_b(t_phsw *data, t_chunk *to_sort, t_stack *stk,int max);

#endif
