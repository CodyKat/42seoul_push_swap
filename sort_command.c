/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:21:51 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/25 21:45:49 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_part1(t_info *info, int start, int end, int size)
{
	int		pivot[2];
	int		index;

	index = 0;
	pivot[0] = start + size / 3;
	pivot[1] = start + size * 2 / 3;

	if (size <= 3)
	{
		sort_three_in_part1(info, size);
		return ;
	}
	while (index < size)
	{
		if (info->stack_b.stack[info->stack_b.front] <= pivot[0])
		{
			push(&info->stack_b, &info->stack_a);
			rotate(&info->stack_a);
		}
		else if (info->stack_b.stack[info->stack_b.front] <= pivot[1])
			push(&info->stack_b, &info->stack_a);
		else
			rotate(&info->stack_b);
		index++;
	}
	sort_part3(info, start, pivot[0], pivot[0] - start + 1);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	sort_part2(info, pivot[0] + 1, pivot[1] - 1, pivot[1] - pivot[0]);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	sort_part4(info, pivot[1], end, end - pivot[1] + 1);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	back_blocks_part1(info, pivot, start, end);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
}

void sort_part2(t_info *info, int start, int end, int size)
{
	int		pivot[2];
	int		index;

	index = 0;
	pivot[0] = start + size / 3;
	pivot[1] = start + size * 2 / 3;

	if (size <= 3)
	{
		sort_three_in_part2(info, size);
		return ;
	}
	while (index < size)
	{
		if (info->stack_a.stack[info->stack_a.front] <= pivot[0])
		{
			push(&info->stack_a, &info->stack_b);
			rotate(&info->stack_b);
		}
		else if (info->stack_a.stack[info->stack_a.front] <= pivot[1])
			push(&info->stack_a, &info->stack_b);
		else
			rotate(&info->stack_a);
		index++;
	}
	sort_part4(info, start, pivot[0], pivot[0] - start + 1);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	sort_part1(info, pivot[0] + 1, pivot[1], pivot[1] - pivot[0]);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	sort_part3(info, pivot[1] + 1, end, end - pivot[1]);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	back_blocks_part2(info, pivot, start, end);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
}

void sort_part3(t_info *info, int start, int end, int size)
{
	int		pivot[2];
	int		index;

	index = 0;
	pivot[0] = start + size / 3;
	pivot[1] = start + size * 2 / 3;

	if (size <= 3)
	{
	//	sort_case_three_part3(&info->stack_a, size);
		return ;
	}
	while (index < size)
	{
		if (info->stack_a.stack[info->stack_a.rear] <= pivot[0])
		{
			rrotate(&info->stack_a);
			push(&info->stack_a, &info->stack_b);
			rotate(&info->stack_b);
		}
		else if (info->stack_a.stack[info->stack_a.rear] <= pivot[1])
		{
			rrotate(&info->stack_a);
			push(&info->stack_a, &info->stack_b);
		}
		else
			rrotate(&info->stack_a);
		index++;
	}
	sort_part4(info, start, pivot[0], pivot[0] - start + 1);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	sort_part1(info, pivot[0] + 1, pivot[1], pivot[1] - pivot[0]);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	sort_part2(info, pivot[1] + 1, end, end - pivot[1]);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	back_blocks_part3(info, pivot, start, end);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
}

void sort_part4(t_info *info, int start, int end, int size)
{
	int		pivot[2];
	int		index;

	index = 0;
	pivot[0] = start + size / 3;
	pivot[1] = start + size * 2 / 3;

	if (size <= 3)
	{
	//	sort_case_three_part4(&info->stack_b, size);
		return ;
	}
	while (index < size)
	{
		if (info->stack_b.stack[info->stack_b.rear] <= pivot[0])
		{
			rrotate(&info->stack_b);
			push(&info->stack_b, &info->stack_a);
			rotate(&info->stack_a);
		}
		else if (info->stack_b.stack[info->stack_b.rear] <= pivot[1])
		{
			rrotate(&info->stack_b);
			push(&info->stack_b, &info->stack_a);
		}
		else
			rrotate(&info->stack_b);
		index++;
	}
	sort_part3(info, start, pivot[0], pivot[0] - start + 1);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	sort_part2(info, pivot[0] + 1, pivot[1], pivot[1] - pivot[0]);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	sort_part1(info, pivot[1] + 1, end, end - pivot[1]);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
	back_blocks_part4(info, pivot, start, end);
//	print_stack(&info->stack_a);
//	print_stack(&info->stack_b);
}
