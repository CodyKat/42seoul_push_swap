/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:04:44 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 09:24:10 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	qa_sort_small_size(t_info *info, int size)
{
	if (size == 3)
		sort_qa_case_3(info);
	else if (size == 2)
		sort_qa_case_2(info);
	else if (size == 1)
		return ;
	else if (size == 4)
		sort_qa_case_4(info);
}

void	qb_sort_small_size(t_info *info, int size)
{
	if (size == 3)
		sort_qb_case_3(info);
	else if (size == 2)
		sort_qb_case_2(info);
	else if (size == 1)
		return ;
	else if (size == 4)
		sort_qb_case_4(info);
}
