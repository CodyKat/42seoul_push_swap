/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pivots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:45:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/06/29 11:05:46 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivots_a(t_info *info, int size, int *pivots)
{
	t_node	*cur_node;
	int		min;
	int		count;

	cur_node = info->a_front;
	min = cur_node->data;
	count = 0;
	while (count < size)
	{
		if (cur_node->data < min)
			min = cur_node->data;
		cur_node = cur_node->next;
		count++;
	}
	pivots[0] = min;
	pivots[1] = min + size / 3;
	pivots[2] = min + size * 2 / 3;
	pivots[3] = min + size - 1;
}

void	set_pivots_b(t_info *info, int size, int *pivots)
{
	t_node	*cur_node;
	int		min;
	int		count;

	cur_node = info->b_front;
	min = cur_node->data;
	count = 0;
	while (count < size)
	{
		if (cur_node->data < min)
			min = cur_node->data;
		cur_node = cur_node->next;
		count++;
	}
	pivots[0] = min;
	pivots[1] = min + size / 3;
	pivots[2] = min + size * 2 / 3;
	pivots[3] = min + size - 1;
}
