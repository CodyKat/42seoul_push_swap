/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:41:49 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 09:25:07 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	qa_processing(t_info *info, int *pivots)
{
	int	block_size;

	block_size = pivots[3] - pivots[2] + 1;
	move_bottom_of_a_to_top(info, block_size);
	qa(info, block_size);
	block_size = pivots[2] - pivots[1];
	qb(info, block_size);
	while (block_size--)
		pa(info);
	block_size = pivots[1] - pivots[0];
	move_bottom_of_b_to_top(info, block_size);
	qb(info, block_size);
	while (block_size--)
		pa(info);
}

void	qa(t_info *info, int size)
{
	int	pivots[4];

	set_pivots_a(info, size, pivots);
	if (size < 5)
		qa_sort_small_size(info, size);
	else
	{
		while (size--)
		{
			if (info->a_front->data < pivots[1])
			{
				pb(info);
				rb(info);
			}
			else if (info->a_front->data < pivots[2])
				pb(info);
			else
				ra(info);
		}
		qa_processing(info, pivots);
	}
}

void	qb_processing(t_info *info, int	*pivots)
{
	int	block_size;

	block_size = pivots[1] - pivots[0];
	move_bottom_of_b_to_top(info, block_size);
	qb(info, block_size);
	block_size = pivots[2] - pivots[1];
	qa(info, block_size);
	while (block_size--)
		pb(info);
	block_size = pivots[3] - pivots[2] + 1;
	move_bottom_of_a_to_top(info, block_size);
	qa(info, block_size);
	while (block_size--)
		pb(info);
}

void	qb(t_info *info, int size)
{
	int	pivots[4];

	set_pivots_b(info, size, pivots);
	if (size < 5)
		qb_sort_small_size(info, size);
	else
	{
		while (size--)
		{
			if (info->b_front->data < pivots[1])
				rb(info);
			else if (info->b_front->data < pivots[2])
				pa(info);
			else
			{
				pa(info);
				ra(info);
			}
		}
		qb_processing(info, pivots);
	}
}
