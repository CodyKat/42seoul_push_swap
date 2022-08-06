/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:52:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/11 16:40:40 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_new_node(t_info *info, int data);

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == 0)
		ft_error();
	info->a_front = 0;
	info->a_rear = 0;
	info->b_front = 0;
	info->b_rear = 0;
	info->size_a = 0;
	info->size_b = 0;
	info->command = 0;
	return (info);
}

void	print_commands(t_info *info)
{
	t_command	*cur_command;
	int			command_num;

	cur_command = info->command;
	while (cur_command)
	{
		command_num = cur_command->command;
		if (command_num == 0)
			write(1, "pa\n", 3);
		else if (command_num == 1)
			write(1, "pb\n", 3);
		else if (command_num == 2)
			write(1, "sa\n", 3);
		else if (command_num == 3)
			write(1, "sb\n", 3);
		else if (command_num == 4)
			write(1, "ra\n", 3);
		else if (command_num == 5)
			write(1, "rb\n", 3);
		else if (command_num == 6)
			write(1, "rra\n", 4);
		else if (command_num == 7)
			write(1, "rrb\n", 4);
		cur_command = cur_command->next;
	}
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc < 2)
		return (0);
	info = init_info();
	parsing(info, argv + 1);
	if (info->size_a < 2)
		exit(0);
	if (check_is_sorted_a(info, info->size_a))
		exit(0);
	sort(info);
	print_commands(info);
	exit(0);
}
