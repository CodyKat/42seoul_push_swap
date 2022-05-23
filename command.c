/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:51:18 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/23 16:32:31 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(void);

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->stack[(stack->front + 1) % stack->cap];
	stack->stack[(stack->front + 1) % stack->cap] = stack->stack[stack->front];
	 stack->stack[stack->front] = tmp;
}

void	push(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		ft_error();
	to->front--;
    if (to->rear == - 1)
        to->rear = to->cap - 1;
	if (to->front == -1)
		to->front = to->cap - 1;
	to->stack[to->front] = from->stack[from->front];
	from->front++;
	if (from->front == from->cap)
		from->front = 0;
	from->size--;
	to->size++;
}

void	rotate(t_stack *stack)
{
	stack->rear++;
	if (stack->rear == stack->cap)
		stack->rear = 0;
	stack->stack[stack->rear] = stack->stack[stack->front];
	stack->front++;
	if (stack->front == stack->cap)
		stack->front = 0;
}

void	rrotate(t_stack *stack)
{
	stack->front--;
	if (stack->front < 0)
		stack->front = stack->cap - 1;
	stack->stack[stack->front] = stack->stack[stack->rear];
	stack->rear--;
	if (stack->rear < 0)
		stack->rear = stack->cap - 1;
}

void	print_stack(t_stack *stack)
{
	int	count;
	int	print_index;

	count = 0;
	print_index = stack->front;
	while (1)
	{
		printf(" %d", stack->stack[print_index]);
		if (print_index == stack->rear)
			break;
		print_index++;
		if (print_index == stack->cap)
			print_index = 0;
	}
	printf("\n");
}
