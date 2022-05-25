/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:25:58 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/25 17:48:03 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_stack *stack)
{
	int	count;
	int	cur;
	int	next;

	count = stack->size - 1;
	while (count--)
	{
		cur = stack->stack[stack->front + count + 1];
		next = stack->stack[(stack->front + 1 + count + 1) % stack->cap];
		if (cur < next)
			break;
	}
	if (count == -1)
		return (1);
	count = stack->size - 1;
	while (count--)
	{
		cur = stack->stack[stack->front + count + 1];
		next = stack->stack[(stack->front + 1 + count + 1) % stack->cap];
		if (cur > next)
			break;
	}
	if (count == -1)
		return (1);
	return (0);
}

void	sort_case_in_three(t_stack *stack, int size)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->stack[stack->front];
	mid = stack->stack[(stack->front + 1) % stack->cap];
	bot = stack->stack[(stack->front + 2) % stack->cap];
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (top < mid)
			swap(stack);
		return ;
	}
	else if (size == 3)
	{
		if (((bot > mid) && (mid > top)) || ((mid > top) && (top > bot)) ||\
				((top > bot) && (bot > mid)))
			swap(stack);
		if (((bot > mid) && (mid > top)) || ((bot > top) && (top > mid)))
			rrotate(stack);
		if (((mid > bot) && (bot > top)) || ((top > bot) && (bot > mid)))
			rotate(stack);
	}
}
