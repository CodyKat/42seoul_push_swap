/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/21 04:54:28 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN (-2147483648)

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->stack = (int *)malloc(sizeof(int));
	stack_b->stack = (int *)malloc(sizeof(int));
	stack_a->cap = 0;
	stack_b->cap = 0;
	stack_a->front = 0;
	stack_b->front = 0;
	stack_a->rear = -1;
	stack_b->rear = -1;
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		command_set[2];

	init_stack(&stack_a, &stack_b);
	parsing(&stack_a, &stack_b, argv + 1);
	sort(&stack_a, &stack_b);
	print_stack(&stack_a);
	//print_stack(&stack_b);
//	print_stack(&stack_b);
	// 여기까지 디버깅성공
    //free(stack_b.stack);
	return (0);
}
