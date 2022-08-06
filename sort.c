/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:48:21 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 09:02:15 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_two_a(t_info *info)
{
	t_node	*top;
	t_node	*mid;

	top = info->a_front;
	mid = top->next;
	if (top->data > mid->data)
		sa(info);
}

void	sort_case_three_a(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->a_front->data;
	mid = info->a_front->next->data;
	bot = info->a_front->next->next->data;
	if (mid > bot && bot > top)
	{
		rra(info);
		sa(info);
	}
	else if (bot > top && top > mid)
		sa(info);
	else if (mid > top && top > bot)
		rra(info);
	else if (top > bot && bot > mid)
		ra(info);
	else if (top > mid && mid > bot)
	{
		ra(info);
		sa(info);
	}
}

void	sort_case_three_b(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->b_front->data;
	mid = info->b_front->next->data;
	bot = info->b_front->next->next->data;
	if (mid > top && top > bot)
	{
		rra(info);
		sa(info);
	}
	else if (top > bot && bot > mid)
		sa(info);
	else if (mid > bot && bot > top)
		rra(info);
	else if (bot > top && top > mid)
		ra(info);
	else if (bot > mid && mid > top)
	{
		ra(info);
		sa(info);
	}
}

void	sort(t_info *info)
{
	if (info->size_a == 2)
		sort_case_two_a(info);
	else if (info->size_a == 3)
		sort_case_three_a(info);
	else
	{
		qa(info, info->size_a);
		clean_commands(info);
	}
}
