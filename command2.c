/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:38:17 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/10 16:09:56 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_info *info)
{
	t_node	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->b_front;
	info->b_front = tmp->next;
	info->b_front->prev = 0;
	tmp->next = 0;
	tmp->prev = info->b_rear;
	info->b_rear->next = tmp;
	info->b_rear = tmp;
	put_command(info, RB);
}

void	rra(t_info *info)
{
	t_node	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->a_rear;
	info->a_rear = tmp->prev;
	info->a_rear->next = 0;
	tmp->prev = 0;
	tmp->next = info->a_front;
	info->a_front->prev = tmp;
	info->a_front = tmp;
	put_command(info, RRA);
}

void	rrb(t_info *info)
{
	t_node	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->b_rear;
	info->b_rear = tmp->prev;
	info->b_rear->next = 0;
	tmp->prev = 0;
	tmp->next = info->b_front;
	info->b_front->prev = tmp;
	info->b_front = tmp;
	put_command(info, RRB);
}

void	put_command(t_info *info, int command)
{
	t_command	*new_command;
	t_command	*last_command;

	new_command = (t_command *)malloc(sizeof(t_command));
	if (new_command == 0)
		ft_error();
	new_command->command = command;
	new_command->next = 0;
	if (info->command == 0)
	{
		new_command->prev = 0;
		info->command = new_command;
		return ;
	}
	last_command = info->command;
	while (last_command->next)
		last_command = last_command->next;
	new_command->prev = last_command;
	last_command->next = new_command;
}

void	input_new_node(t_info *info, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == 0)
		ft_error();
	new_node->data = data;
	new_node->next = 0;
	if (info->a_front == 0)
	{
		info->a_front = new_node;
		new_node->next = 0;
		info->a_rear = new_node;
		info->size_a++;
		return ;
	}
	info->a_rear->next = new_node;
	new_node->prev = info->a_rear;
	info->a_rear = new_node;
	info->size_a++;
}
