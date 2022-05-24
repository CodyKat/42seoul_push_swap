/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:19:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/24 19:48:37 by jaemjeon         ###   ########.fr       */
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

void	init_stack(t_info *info)
{
	info->stack_a.stack = (int *)malloc(sizeof(int));
	info->stack_a.size = 0;
	info->stack_b.size = 0;
	info->stack_a.cap = 0;
	info->stack_b.cap = 0;
	info->stack_a.front = 0;
	info->stack_b.front = 0;
	info->stack_a.rear = -1;
	info->stack_b.rear = -1;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	init_stack(&info);
	parsing(&info, argv + 1);
	sort(&info);
	print_stack(&info.stack_a);
	print_stack(&info.stack_b);
	free(info.stack_b.stack);
	free(info.stack_a.stack);
	return (0);
}
