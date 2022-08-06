/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:07:05 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/11 16:59:25 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN (-2147483648)

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	updata_stack(t_info *info, int *index_stack)
{
	t_node	*cur_node;

	cur_node = info->a_front;
	while (cur_node)
	{
		cur_node->data = *index_stack;
		cur_node = cur_node->next;
		index_stack++;
	}
	free(index_stack - info->size_a);
}

void	make_linear_stack(t_info *info)
{
	t_node	*circuit;
	t_node	*cur_node;
	int		*index_stack;
	int		rank;
	int		index;

	index_stack = (int *)malloc(sizeof(int) * info->size_a);
	if (index_stack == 0)
		ft_error();
	cur_node = info->a_front;
	index = -1;
	while (cur_node)
	{
		rank = 0;
		circuit = info->a_front;
		while (circuit)
		{
			if (circuit->data <= cur_node->data)
				rank++;
			circuit = circuit->next;
		}
		index_stack[++index] = rank;
		cur_node = cur_node->next;
	}
	updata_stack(info, index_stack);
}

void	check_has_dup(t_info *info)
{
	t_node	*front;
	t_node	*rear;

	if (info->size_a < 2)
		return ;
	front = info->a_front;
	while (front != info->a_rear)
	{
		rear = front->next;
		while (rear)
		{
			if (front->data == rear->data)
				ft_error();
			rear = rear->next;
		}
		front = front->next;
	}
}

void	parsing(t_info *info, char *argv[])
{
	char	**splited_argv;
	long	cur_data;
	int		idx;

	while (*argv)
	{
		idx = 0;
		splited_argv = ft_split(*argv, ' ');
		while (splited_argv[idx])
		{
			cur_data = ft_atol(splited_argv[idx]);
			if ((cur_data < INT_MIN) || (cur_data > INT_MAX))
				ft_error();
			input_new_node(info, cur_data);
			free(splited_argv[idx]);
			idx++;
		}
		argv++;
		free(splited_argv);
	}
	if (info->size_a < 1)
		ft_error();
	check_has_dup(info);
	make_linear_stack(info);
}
