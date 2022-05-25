/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_command_processing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:16:15 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/25 20:59:41 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_blocks_part1(t_info *info, int *pivot, int start, int end)
{
	int	count;

	count = pivot[0] - start + 1;
	while (count--)
	{
		rrotate(&info->stack_a);
		push(&info->stack_a, &info->stack_b);
	}
	sort_three_in_part2(info, pivot[0] - start + 1);
	count = pivot[1] - pivot[0] + 1;
	while (count--)
		push(&info->stack_a, &info->stack_b);
	count = end - pivot[1] + 1;
	while (count--)
		rrotate(&info->stack_b);
	sort_three_in_part1(info, end - pivot[1] + 1);
}

void	back_blocks_part2(t_info *info, int *pivot, int start, int end)
{
	int	count;

	count = end - pivot[1] + 1;
	while (--count)
		rrotate(&info->stack_a);
	sort_three_in_part2(info, end - pivot[1] + 1);
	count = pivot[1] - pivot[0] + 1;
	while (--count)
		push(&info->stack_b, &info->stack_a);
	count = pivot[0] - start + 2;
	while (--count)
	{
		rrotate(&info->stack_b);
		push(&info->stack_b, &info->stack_a);
	}
	sort_three_in_part2(info, pivot[0] - start + 1);
}

void	back_blocks_part3(t_info *info, int *pivot, int start, int end)
{
	int	count;

	count = pivot[0] - start + 1;
	while (--count)
	{
		rrotate(&info->stack_b);
		push(&info->stack_b, &info->stack_a);
	}
	sort_three_in_part2(info, pivot[0] - start + 1);
	count = pivot[0] - start + 1;
	while (--count)
		rotate(&info->stack_a);
	sort_three_in_part1(info, pivot[1] - pivot[0] + 1);
	count = pivot[1] - pivot[0] + 1;
	while (--count)
	{
		push(&info->stack_b, &info->stack_a);
		rotate(&info->stack_a);
	}
	sort_three_in_part2(info, end - pivot[1] + 1);
	count = end - pivot[1] + 1;
	while (--count)
		rotate(&info->stack_a);
}

void	back_blocks_part4(t_info *info, int *pivot, int start, int end)
{
	int	count;

	count = pivot[0] - start + 2;
	while (--count)
		rrotate(&info->stack_a);
	sort_three_in_part2(info, pivot[0] - start + 1);
	count = pivot[0] - start + 2;
	while (--count)
	{
		push(&info->stack_a, &info->stack_b);
		rotate(&info->stack_b);
	}


	sort_three_in_part2(info, pivot[1] - pivot[0]);
	count = pivot[1] - pivot[0] + 1;
	while (--count)
	{
		push(&info->stack_a, &info->stack_b);
		rotate(&info->stack_b);
	}



	sort_three_in_part1(info, end - pivot[1]);
	count = end - pivot[1] + 1;
	while (--count)
		rotate(&info->stack_b);
}
