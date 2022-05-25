/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:15:58 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/25 16:08:04 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#define INT_MAX 2147483647
#define INT_MIN (-2147483648)

long	ft_atol(char *argv);
void	ft_error(void);
char	**ft_split(const char *s, char c);

void	free_argv_string(char **table)
{
	char	**circuit;

	circuit = table;
	while (*circuit)
	{
		free(*circuit);
		circuit++;
	}
	free(table);
}

void	push_stack(t_stack *stack, char *circuit_argv_string)
{
	int		*new_address;
	int		offset;
	long	new_element;

	offset = 0;
	new_address = (int *)malloc(sizeof(int) * (stack->cap + 1));
	if (new_address == 0)
		ft_error();
	while (offset < stack->cap)
	{
		new_address[offset] = stack->stack[offset];
		offset++;
	}
	new_element = ft_atol(circuit_argv_string);
	if ((INT_MIN > new_element) || (new_element > INT_MAX))
		ft_error();
	new_address[offset] = (int)new_element;
	stack->rear++;
	stack->cap++;
	free(stack->stack);
	stack->stack = new_address;
}

void	make_linear_stack(t_stack *stack)
{
	int	*new_stack;
	int	index;
	int	circuit;
	int	rank;

	new_stack = (int *)malloc(sizeof(int) * stack->cap);
	if (new_stack == 0)
		ft_error();
	index = 0;
	while (index < stack->cap)
	{
		rank = 0;
		circuit = 0;
		while (circuit < stack->cap)
		{
			if (stack->stack[circuit] <= stack->stack[index])
				rank++;
			circuit++;
		}
		new_stack[index] = rank;
		index++;
	}
	free(stack->stack);
	stack->stack = new_stack;
}

void	check_has_dup_empty(t_stack *stack)
{
	int	front;
	int	rear;

	if (stack->cap == 0)
		ft_error();
	front = 0;
	while (front < stack->cap - 1)
	{
		rear = front + 1;;
		while (rear < stack->cap)
		{
			if (stack->stack[front] == stack->stack[rear])
				ft_error();
			rear++;
		}
		front++;
	}
}

void	parsing(t_info *info, char **argv)
{
	int		stack_size;
	long	cur_num;
	char	**argv_string;
	char	**circuit_argv_string;

	while (*argv)
	{
		argv_string = ft_split(*argv, ' ');
		circuit_argv_string = argv_string;
		while (*circuit_argv_string)
		{
			push_stack(&info->stack_a, *circuit_argv_string);
			circuit_argv_string++;
		}
		free_argv_string(argv_string);
		argv++;
	}
	make_linear_stack(&info->stack_a);
	check_has_dup_empty(&info->stack_a);
	info->stack_a.size = info->stack_a.cap;
	info->stack_b.cap = info->stack_a.cap;
	info->stack_b.stack = (int *)malloc(sizeof(int) * info->stack_b.cap);
}
