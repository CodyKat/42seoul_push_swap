/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/15 15:10:57 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN (-2147483648)

long	ft_atol(char *argv);
void	*ft_calloc(size_t count, size_t size);
void	check_has_dup_stack(int *stack_a, int size);
void	swap(t_stack *stack);
void	push_to_from(t_stack *from, t_stack *to);
void	rotate_stack(t_stack *stack);
void	rrotate_stack(t_stack *stack);
void	print_stack(t_stack *stack);

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	parsing(int *stack_a, int size, char **argv)
{
	int		*origin_stack;
	int		index;
	long	cur_num;

	index = 0;
	origin_stack = (int *)malloc(sizeof(size));
	while (index < size)
	{
		cur_num = ft_atol(argv[index]);
		if ((INT_MIN <= cur_num) && (cur_num <= INT_MAX))
		{
			
			stack_a[index] = (int)cur_num;
		}
		else
			ft_error();
		index++;
	}
	free(origin_stack);
}

void	check_dup_input(int *stack_a, int size)
{
	int	x;
	int	y;

	if (size == 0)
		ft_error();
	x = 0;
	while (x < size - 1)
	{
		y = x + 1;
		while (y < size)
		{
			if (stack_a[x] == stack_a[y])
				ft_error();
			y++;
		}
		x++;
	}
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->stack = (int *)calloc(sizeof(int), size * 2);
	stack_b->stack = (int *)calloc(sizeof(int), size * 2);
	stack_a->cap = size * 2;
	stack_b->cap = size * 2;
	stack_a->front = 0;
	stack_b->front = 1;
	stack_a->rear = size - 1;
	stack_b->rear = 0;
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		command_set[2];
	int		pivot[2];

	init_stack(&stack_a, &stack_b, argc - 1);
	parsing(stack_a.stack, argc - 1, argv + 1);
	check_dup_input(stack_a.stack, argc - 1);

//	push_to_from(&stack_a, &stack_b);
//	push_to_from(&stack_a, &stack_b);
//	rotate_stack(&stack_a);
//	print_stack(&stack_a);
//	print_stack(&stack_b);
	// 여기까지 디버깅성공
	return (0);
}
