/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_case_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:37:04 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/06/29 10:46:27 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_qa_case_3(t_info *info)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bot;

	top = info->a_front;
	mid = top->next;
	bot = mid->next;
	if ((top ->data < mid->data) && (mid->data < bot->data))
		return ;
	if ((top->data > mid->data) && (top->data > bot->data))
		sa(info);
	if (!((bot->data > mid->data) && (bot->data > top->data)))
	{
		pb(info);
		sa(info);
		pa(info);
	}
	if (((mid->data < bot->data) && (bot->data < top->data)) \
		|| ((top->data < bot->data) && (bot->data < mid->data)))
		return ;
	sa(info);
	return ;
}

void	sort_qb_case_3(t_info *info)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bot;

	top = info->b_front;
	mid = top->next;
	bot = mid->next;
	if ((top->data > mid->data) && (mid->data > bot->data))
		return ;
	if ((top->data < mid->data) && (top->data < bot->data))
		sb(info);
	if (!((bot->data < mid->data) && (bot->data < top->data)))
	{
		pa(info);
		sb(info);
		pb(info);
	}
	if (((mid->data < bot->data) && (bot->data < top->data)) \
		|| ((top->data < bot->data) && (bot->data < mid->data)))
		return ;
	sb(info);
	return ;
}

void	sort_qa_case_2(t_info *info)
{
	t_node	*top;
	t_node	*bot;

	top = info->a_front;
	bot = top->next;
	if (bot->data < top->data)
		sa(info);
}

void	sort_qb_case_2(t_info *info)
{
	t_node	*top;
	t_node	*bot;

	top = info->b_front;
	bot = top->next;
	if (bot->data > top->data)
		sb(info);
}
