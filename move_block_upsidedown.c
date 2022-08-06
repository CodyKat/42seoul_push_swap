/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_block_upsidedown.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:55:57 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 03:49:05 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_bottom_of_a_to_top(t_info *info, int bot_size)
{
	int	up_size;

	up_size = info->size_a - bot_size;
	if (up_size < bot_size)
	{
		while (up_size > 0)
		{
			ra(info);
			up_size--;
		}
	}
	else
	{
		while (bot_size > 0)
		{
			rra(info);
			bot_size--;
		}
	}
}

void	move_bottom_of_b_to_top(t_info *info, int bot_size)
{
	int	up_size;

	up_size = info->size_b - bot_size;
	if (up_size < bot_size)
	{
		while (up_size > 0)
		{
			rb(info);
			up_size--;
		}
	}
	else
	{
		while (bot_size > 0)
		{
			rrb(info);
			bot_size--;
		}
	}
}
