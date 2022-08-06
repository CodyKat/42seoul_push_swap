/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:06:47 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 09:29:54 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

enum e_command
{
	PA = 0,
	PB,
	SA,
	SB,
	RA,
	RB,
	RRA,
	RRB
};

typedef struct s_command
{
	int					command;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_info
{
	t_node		*a_front;
	t_node		*a_rear;
	t_node		*b_front;
	t_node		*b_rear;
	int			size_a;
	int			size_b;
	t_command	*command;
}	t_info;

void	pa(t_info *info);
void	pb(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	qa(t_info *info, int size);
void	qb(t_info *info, int size);
void	put_command(t_info *info, int command);
void	parsing(t_info *info, char *argv[]);
void	sort(t_info *info);
void	sort_qa_case_2(t_info *info);
void	sort_qb_case_2(t_info *info);
void	sort_qa_case_3(t_info *info);
void	sort_qb_case_3(t_info *info);
void	sort_qa_case_4(t_info *info);
void	sort_qb_case_4(t_info *info);
void	ft_error(void);
void	clean_commands(t_info *info);
void	move_bottom_of_a_to_top(t_info *info, int bot_size);
void	move_bottom_of_b_to_top(t_info *info, int bot_size);
void	input_new_node(t_info *info, int data);
void	set_pivots_a(t_info *info, int size, int *pivots);
void	set_pivots_b(t_info *info, int size, int *pivots);
void	qa_sort_small_size(t_info *info, int size);
void	qb_sort_small_size(t_info *info, int size);

int		check_is_sorted_a(t_info *info, int size);
int		check_is_sorted_b(t_info *info, int size);

long	ft_atol(char *argv);

char	**ft_split(const char *s, char c);

#endif
