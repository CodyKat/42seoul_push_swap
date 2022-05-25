/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:27:06 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/25 21:36:28 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_in_part1(t_info *info, int size)
{
	int	top;
	int	mid;
	int	bot;

	top = info->stack_b.stack[info->stack_b.front];
	mid = info->stack_b.stack[(info->stack_b.front + 1) % info->stack_b.cap];
	bot = info->stack_b.stack[(info->stack_b.front + 2) % info->stack_b.cap];
	if (size == 2 && top < mid)
	{
		swap(&info->stack_b);
		return ;
	}
	else if (size == 1 || (size == 2 && top > mid) || size > 3)
		return ;
	if ((mid < top) && (mid < bot))
	{
		push(&info->stack_b, &info->stack_a);
		swap(&info->stack_b);
		push(&info->stack_a, &info->stack_b);
		if (top < bot)
			swap(&info->stack_b);
	}
	else if ((bot < top) && (top < mid))
		swap(&info->stack_b);
	else if ((top < bot) && (bot < mid))
	{
		push(&info->stack_b, &info->stack_a);
		push(&info->stack_b, &info->stack_a);
		swap(&info->stack_a);
		push(&info->stack_b, &info->stack_a);
		swap(&info->stack_a);
		push(&info->stack_a, &info->stack_b);
		push(&info->stack_a, &info->stack_b);
		push(&info->stack_a, &info->stack_b);
	}
	else if ((bot > mid) && (mid > top))
	{
		push(&info->stack_b, &info->stack_a);
		swap(&info->stack_b);
		push(&info->stack_b, &info->stack_a);
		swap(&info->stack_a);
		push(&info->stack_b, &info->stack_a);
		swap(&info->stack_a);
		push(&info->stack_a, &info->stack_b);
		push(&info->stack_a, &info->stack_b);
		push(&info->stack_a, &info->stack_b);
	}
}

void	sort_three_in_part2(t_info *info, int size)
{
	int	top;
	int	mid;
	int	bot;

	top = info->stack_a.stack[info->stack_a.front];
	mid = info->stack_a.stack[(info->stack_a.front + 1) % info->stack_a.cap];
	bot = info->stack_a.stack[(info->stack_a.front + 2) % info->stack_a.cap];
	if (size == 2 && top > mid)
	{
		swap(&info->stack_b);
		return ;
	}
	else if (size == 1 || (size == 2 && top < mid) || size > 3)
		return ;
	if ((mid > top) && (mid > bot))
	{
		push(&info->stack_a, &info->stack_b);
		swap(&info->stack_a);
		push(&info->stack_b, &info->stack_a);
		if (top > bot)
			swap(&info->stack_a);
	}
	else if ((mid < top) && (mid < bot))
	{
		swap(&info->stack_a);
		if (top > bot)
		{
			push(&info->stack_a, &info->stack_b);
			swap(&info->stack_a);
			push(&info->stack_b, &info->stack_a);
		}
	}
	else if ((top > mid) && (mid > bot))
	{
		swap(&info->stack_a);
		push(&info->stack_a, &info->stack_b);
		swap(&info->stack_a);
		push(&info->stack_b, &info->stack_a);
		swap(&info->stack_a);
	}
}
