/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:03:14 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 01:47:45 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_in_4(t_node *node1, t_node *node2, t_node *node3, t_node *node4)
{
	int	max;

	max = node1->data;
	if (max < node2->data)
		max = node2->data;
	if (max < node3->data)
		max = node3->data;
	if (max < node4->data)
		max = node4->data;
	return (max);
}

int	find_min_in_4(t_node *node1, t_node *node2, t_node *node3, t_node *node4)
{
	int	min;

	min = node1->data;
	if (min > node2->data)
		min = node2->data;
	if (min > node3->data)
		min = node3->data;
	if (min > node4->data)
		min = node4->data;
	return (min);
}

void	sort_qa_case_4(t_info *info)
{
	t_node	*node_list[4];
	int		max;

	node_list[0] = info->a_front;
	node_list[1] = node_list[0]->next;
	node_list[2] = node_list[1]->next;
	node_list[3] = node_list[2]->next;
	max = find_max_in_4(node_list[0], node_list[1], node_list[2], node_list[3]);
	if (node_list[0]->data == max)
		sa(info);
	if ((node_list[0]->data == max) || (node_list[1]->data == max))
	{
		pb(info);
		sa(info);
	}
	if (node_list[2]->data == max)
		pb(info);
	if (node_list[3]->data != max)
	{
		pb(info);
		sa(info);
		pa(info);
		pa(info);
	}
	sort_qa_case_3(info);
}

void	sort_qb_case_4(t_info *info)
{
	t_node	*node_list[4];
	int		min;

	node_list[0] = info->b_front;
	node_list[1] = node_list[0]->next;
	node_list[2] = node_list[1]->next;
	node_list[3] = node_list[2]->next;
	min = find_min_in_4(node_list[0], node_list[1], node_list[2], node_list[3]);
	if (node_list[0]->data == min)
		sb(info);
	if ((node_list[0]->data == min) || (node_list[1]->data == min))
	{
		pa(info);
		sb(info);
	}
	if (node_list[2]->data == min)
		pa(info);
	if (node_list[3]->data != min)
	{
		pa(info);
		sb(info);
		pb(info);
		pb(info);
	}
	sort_qb_case_3(info);
}
