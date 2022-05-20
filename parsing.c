/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:15:58 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/19 20:02:27 by jaemjeon         ###   ########.fr       */
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

void	push_stack(t_stack *stack, int old_size, char *circuit_argv_string)
{
	int		*new_address;
	int		offset;
	long	new_element;

	offset = 0;
	new_address = (int *)malloc(sizeof(int) * old_size + 1);
	if (new_address == 0)
		ft_error();
	while (offset < old_size)
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

void	parsing(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	int		stack_size;
	long	cur_num;
	char	**argv_string;
	char	**circuit_argv_string;

	stack_size = 0;
	while (*argv)
	{
		argv_string = ft_split(*argv, ' ');
		circuit_argv_string = argv_string;
		while (*circuit_argv_string)
		{
			push_stack(stack_a, stack_size, *circuit_argv_string);
			stack_size++;
			circuit_argv_string++;
		}
		free_argv_string(argv_string);
		argv++;
	}
	make_linear_stack(stack_a);
	stack_b->cap = stack_a->cap;
	check_has_dup_empty(stack_a);
}
