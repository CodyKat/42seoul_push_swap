/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:25:58 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/21 04:56:36 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_three(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = stack_a->stack[stack_a->front];
	mid = stack_a->stack[(stack_a->front + 1) % stack_a->cap];
	bot = stack_a->stack[(stack_a->front + 2) % stack_a->cap];
	
	if ((bot > top) && (top > mid))
		swap(stack_a);
	else if ((mid > bot) && (bot > top))
	{
		swap(stack_a);
		rotate(stack_a);
	}
	else if ((top > bot) && (bot > mid))
		rotate(stack_a);
	else if ((top > mid) && (mid > bot))
	{
		swap(stack_a);
		rrotate(stack_a);
	}
	else if ((mid > top) && (top > bot))
		rrotate(stack_a);
}
