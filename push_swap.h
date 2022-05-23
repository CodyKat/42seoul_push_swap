/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:06:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/23 16:30:25 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	int	*pivot;
	int	*chunk_size;
}	t_info;

long	ft_atol(char *argv);
void	*ft_calloc(size_t count, size_t size);
void	check_has_dup_stack(int *stack_a, int size);
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	print_stack(t_stack *stack);
void	parsing(t_stack *stack_a, t_stack *stack_b, char **argv);
void	sort_case_three(t_stack *stack_a);
void	sort(t_stack *stack_a, t_stack *stack_b);
