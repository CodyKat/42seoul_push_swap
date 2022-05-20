/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 04:43:34 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/21 04:48:15 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
		printf("more than 3");
}
