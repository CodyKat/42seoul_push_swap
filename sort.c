/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:43:34 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/23 16:33:51 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
		if (stack_a->stack[stack_a->front] < pivot1)
		{
			push(stack_a, stack_b);
			rotate(stack_b);
		}
		else if (stack_a->stack[stack_a->front] < pivot2)
			push(stack_a, stack_b);
		else
			rotate(stack_a);
		index--;
	}
}

void	sort_big_size(t_stack *stack_a, t_stack *stack_b)
{
	partition_three(stack_a, stack_b);
	while (stack_a->size != 0)
		push(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->cap == 2)
	{
		if (stack_a->stack[0] > stack_a->stack[1])
			swap(stack_a);
	}
	else if (stack_a->cap == 3)
		sort_case_three(stack_a);
	else
		sort_big_size(stack_a, stack_b);
}
