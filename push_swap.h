/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:06:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/24 16:12:59 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define PART_1 1
# define PART_2 2
# define PART_3 3
# define PART_4 4
# include <stdlib.h>

typedef struct	s_stack
{
	int	*stack;
	int	front;
	int	rear;
	int	cap;
	int	size;
}	t_stack;

typedef struct	s_info
{
	int		l_pivot[2];
	int		s_pivot[3];
	t_stack	stack_a;
	t_stack	stack_b;
}	t_info;

long	ft_atol(char *argv);
void	*ft_calloc(size_t count, size_t size);
void	check_has_dup_stack(int *stack_a, int size);
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	print_stack(t_stack *stack);
void	parsing(t_info *info, char **argv);
void	sort_case_three(t_stack *stack_a);
void	sort(t_info *info);
void	sort_part1(t_info *info, int start, int end, int size);
void	sort_part2(t_info *info, int start, int end, int size);
void	sort_part3(t_info *info, int start, int end, int size);
void	sort_part4(t_info *info, int start, int end, int size);
void	sort_case_three_part1(t_stack *stack, int size);
void	sort_case_three_part2(t_stack *stack, int size);
void	sort_case_three_part3(t_stack *stack, int size);
void	sort_case_three_part4(t_stack *stack, int size);
void	back_blocks_part1(t_info *info, int *pivot, int start, int end);
void	back_blocks_part2(t_info *info, int *pivot, int start, int end);
void	back_blocks_part3(t_info *info, int *pivot, int start, int end);
void	back_blocks_part4(t_info *info, int *pivot, int start, int end);

#endif
