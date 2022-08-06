/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:35:11 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 09:26:04 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define ABS_INT_MAX 2147483647
#define ABS_INT_MIN 2147483648

void	ft_error(void);

int	ft_isdigit(char ptr)
{
	if ('0' <= ptr && ptr <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != 0)
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (--dstsize > 0)
	{
		if (*src == '\0')
			break ;
		*dst++ = *src++;
	}
	*dst = '\0';
	return (src_len);
}

void	check_is_in_int(int sign, long inspect_num)
{
	if (((sign == -1) && (inspect_num > ABS_INT_MIN)) || \
			((sign == 1) && (inspect_num > ABS_INT_MAX)))
		ft_error();
}

long	ft_atol(char *argv)
{
	long	output;
	int		sign;

	output = 0;
	sign = 1;
	if (*argv == '+')
		argv++;
	else if (*argv == '-')
	{
		argv++;
		sign = -1;
	}
	while (*argv != '\0')
	{
		if (ft_isdigit(*argv))
		{
			output *= 10;
			output += (*argv - '0');
			check_is_in_int(sign, output);
			argv++;
		}
		else
			ft_error();
	}
	return (output * sign);
}
