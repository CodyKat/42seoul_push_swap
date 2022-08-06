/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:40:16 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/11 16:39:58 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted_a(t_info *info, int size)
{
	t_node	*cur_node;
	int		count;

	if (size == 1)
		return (1);
	count = 0;
	cur_node = info->a_front;
	while (count < size - 1)
	{
		if (cur_node->data > cur_node->next->data)
			return (0);
		cur_node = cur_node->next;
		count++;
	}
	return (1);
}
