/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:45:01 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/06/26 12:38:24 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = info->b_front;
	tmp2 = info->a_front;
	if (info->b_front->next)
		info->b_front->next->prev = 0;
	info->a_front = tmp1;
	if (info->size_a == 0)
		info->a_rear = tmp1;
	info->b_front = tmp1->next;
	tmp1->next = tmp2;
	if (tmp2)
		tmp2->prev = tmp1;
	info->size_b--;
	info->size_a++;
	if (info->size_b == 0)
		info->b_rear = 0;
	put_command(info, PA);
}

void	pb(t_info *info)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = info->a_front;
	tmp2 = info->b_front;
	if (info->a_front->next)
		info->a_front->next->prev = 0;
	info->b_front = tmp1;
	if (info->size_b == 0)
		info->b_rear = tmp1;
	info->a_front = tmp1->next;
	tmp1->next = tmp2;
	if (tmp2)
		tmp2->prev = tmp1;
	info->size_a--;
	info->size_b++;
	if (info->size_a == 0)
		info->a_rear = 0;
	put_command(info, PB);
}

void	sa(t_info *info)
{
	t_node	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->a_front;
	info->a_front = info->a_front->next;
	if (info->a_front->next != 0)
		info->a_front->next->prev = tmp;
	tmp->next = info->a_front->next;
	info->a_front->prev = 0;
	info->a_front->next = tmp;
	tmp->prev = info->a_front;
	if (info->size_a == 2)
		info->a_rear = tmp;
	put_command(info, SA);
}

void	sb(t_info *info)
{
	t_node	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->b_front;
	info->b_front = info->b_front->next;
	if (info->b_front->next != 0)
		info->b_front->next->prev = tmp;
	tmp->next = info->b_front->next;
	info->b_front->prev = 0;
	info->b_front->next = tmp;
	tmp->prev = info->b_front;
	if (info->size_b == 2)
		info->b_rear = tmp;
	put_command(info, SB);
}

void	ra(t_info *info)
{
	t_node	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->a_front;
	info->a_front = tmp->next;
	info->a_front->prev = 0;
	tmp->next = 0;
	tmp->prev = info->a_rear;
	info->a_rear->next = tmp;
	info->a_rear = tmp;
	put_command(info, RA);
}
