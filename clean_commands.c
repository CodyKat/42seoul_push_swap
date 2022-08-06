/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:11:37 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 03:38:06 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_command(t_info *info, t_command *node)
{
	if ((node->prev == 0) && (node->next != 0))
	{
		node = node->next;
		free(node->prev);
		node->prev = 0;
		info->command = node;
	}
	else if ((node->prev != 0) && (node->next == 0))
	{
		node = node->prev;
		free(node->next);
		node->next = 0;
	}
	else if ((node->prev == 0) && (node->next == 0))
	{
		free(node);
		info->command = node;
	}
	else
	{
		node = node->prev;
		node->next = node->next->next;
		free(node->next->prev);
		node->next->prev = node;
	}
}

int	have_to_remove(t_command *front)
{
	if (front->next == 0)
		return (0);
	else if ((front->command == PA) && (front->next->command == PB))
		return (1);
	else if ((front->command == PB) && (front->next->command == PA))
		return (1);
	else if ((front->command == RA) && (front->next->command == RRA))
		return (1);
	else if ((front->command == RRA) && (front->next->command == RA))
		return (1);
	else if ((front->command == RB) && (front->next->command == RRB))
		return (1);
	else if ((front->command == RRB) && (front->next->command == RB))
		return (1);
	else if ((front->command == SA) && (front->next->command == SA))
		return (1);
	else if ((front->command == SB) && (front->next->command == SB))
		return (1);
	else
		return (0);
}

void	clean_commands(t_info *info)
{
	t_command	*cur_command;

	cur_command = info->command;
	while (cur_command->next != 0)
	{
		if (have_to_remove(cur_command))
		{
			if (cur_command->prev == 0)
			{
				cur_command = cur_command->next->next;
				remove_command(info, cur_command->prev);
				remove_command(info, cur_command->prev);
				if (cur_command == 0)
					return ;
			}
			else
			{
				cur_command = cur_command->prev->prev;
				remove_command(info, cur_command->next->next);
				remove_command(info, cur_command->next->next);
			}
		}
		cur_command = cur_command->next;
	}
}
