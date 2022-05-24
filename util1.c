/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:20:14 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/24 10:44:47 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isdigit(char ptr)
{
	if ('0' <= ptr && ptr <= '9')
		return (1);
	return (0);
}

long	ft_atol(char *argv)
{
	long	output;
	int		sign;

	output = 0;
	sign = 1;
	if (*argv == '+')
		while (*argv == '+')
			argv++;
	else if (*argv == '-')
	{
		while (*argv == '-')
			argv++;
		sign = -1;
	}
	while (*argv != '\0')
	{
		if (ft_isdigit(*argv))
		{
			output *= 10;
			output += (*argv - '0');
			argv++;
		}
		else
			return (2147483648);
	}
	return (output * sign);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*(char *)s = '\0';
		s++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

int	*ft_realloc(int *address, int size)
{
	int	*new_address;
	int	offset;

	offset = 0;
	new_address = (int *)malloc(sizeof(int) * size);
	while (offset < size)
	{
		new_address[offset] = address[offset];
		offset++;
	}
	free(address);
	return (new_address);
}
