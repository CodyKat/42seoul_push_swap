/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:43:34 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/25 17:50:02 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
void	partition_three(t_stack *stack_a, t_stack *stack_b)
{
	int index;
	int	pivot1;
	int	pivot2;

	index = stack_a->cap;
	pivot1 = stack_a->cap / 3;
	pivot2 = stack_a->cap * 2 / 3;
	while (index)
	{
		if (stack_a->stack[stack_a->front] <= pivot1)
		{
			push(stack_a, stack_b);
			rotate(stack_b);
		}
		else if (stack_a->stack[stack_a->front] <= pivot2)
			push(stack_a, stack_b);
		else
			rotate(stack_a);
		index--;
	}
}

void	sort_big_size(t_info *info)
{
	int	pivot[2];

	pivot[0] = info->stack_a.cap / 3;
	pivot[1] = info->stack_a.cap * 2 / 3;
	partition_three(&info->stack_a, &info->stack_b);
	sort_part3(info, pivot[1] + 1, info->stack_a.cap, info->stack_a.cap - pivot[1]);
	sort_part1(info, pivot[0] + 1, pivot[1], pivot[1] - pivot[0]);
	sort_part4(info, 0, pivot[0], pivot[0]);
	while (info->stack_b.size)
		push(&info->stack_b, &info->stack_a);
}
*/

void	sort(t_info *info)
{
	if (check_is_sorted(&info->stack_a))
		return ;
	else if (info->stack_a.size <= 3)
		sort_case_in_three(&info->stack_a, info->stack_a.size);
	else
		sort_part2(info, 1, info->stack_a.cap, info->stack_a.cap);
}
