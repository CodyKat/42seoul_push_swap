/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:25:58 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/24 16:53:32 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_three_part1(t_stack *stack, int size)
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
	/*
	if ((bot > mid) && (mid > top))
	{
		swap(stack);
		rrotate(stack);
	}
	else if ((mid > bot) && (bot > top))
		rotate(stack);
	else if ((mid > top) && (top > bot))
		swap(stack);
	else if ((bot > top) && (top > mid))
		rrotate(stack);
	else if ((top > bot) && (bot > mid))
	{
		swap(stack);
		rotate(stack);
	}
*/
	if (((bot > mid) && (mid > top)) || ((mid > top) && (top > bot)) ||\
			((top > bot) && (bot > mid)))
		swap(stack);
	if (((bot > mid) && (mid > top)) || ((bot > top) && (top > mid)))
		rrotate(stack);
	if (((mid > bot) && (bot > top)) || ((top > bot) && (bot > mid)))
		rotate(stack);
	
}

void	sort_case_three_part2(t_stack *stack, int size)
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
		if (top > mid)
			swap(stack);
		return ;
	}
	/*
	if ((bot > top) && (top > mid))
		swap(stack);
	else if ((mid > bot) && (bot > top))
	{
		swap(stack);
		rotate(stack);
	}
	else if ((top > bot) && (bot > mid))
		rotate(stack);
	else if ((top > mid) && (mid > bot))
	{
		swap(stack);
		rrotate(stack);
	}
	else if ((mid > top) && (top > bot))
		rrotate(stack);
*/
	if (((bot > top) && (top > mid)) || ((mid > bot) && (bot > top)) ||\
			((top > mid) && (mid > bot)))
		swap(stack);
	if (((mid > bot) && (bot > top)) || ((top > bot) && (bot > mid)))
		rotate(stack);
	if (((top > mid) && (mid > bot)) || ((mid > top) && (top > bot)))
		rrotate(stack);
}

void	sort_case_three_part3(t_stack *stack, int size)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->stack[(stack->rear - 2 + stack->cap) % stack->cap];
	mid = stack->stack[(stack->rear - 1 + stack->cap) % stack->cap];
	bot = stack->stack[stack->rear % stack->cap];
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (mid > bot)
		{
		}
	}
	if ((bot > mid) && (mid > top))
	{
		swap(stack);
		rrotate(stack);
	}
	else if ((mid > bot) && (bot > top))
		rotate(stack);
	else if ((mid > top) && (top > bot))
		swap(stack);
	else if ((bot > top) && (top > mid))
		rrotate(stack);
	else if ((top > bot) && (bot > mid))
	{
		swap(stack);
		rotate(stack);
	}
}

void	sort_case_three_part4(t_stack *stack, int size)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->stack[stack->front];
	mid = stack->stack[(stack->front + 1) % stack->cap];
	bot = stack->stack[(stack->front + 2) % stack->cap];
	if ((bot > mid) && (mid > top))
	{
		swap(stack);
		rrotate(stack);
	}
	else if ((mid > bot) && (bot > top))
		rotate(stack);
	else if ((mid > top) && (top > bot))
		swap(stack);
	else if ((bot > top) && (top > mid))
		rrotate(stack);
	else if ((top > bot) && (bot > mid))
	{
		swap(stack);
		rotate(stack);
	}
}
