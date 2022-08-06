/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:45:50 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/11 16:46:48 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

static int	ft_count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (count);
		while (*s != '\0' && *s != c)
			s++;
		count++;
	}
	return (count);
}

static char	*ft_alloc_string(char **dst, const char *src, char del)
{
	int		len;

	len = 0;
	while (*src == del)
		src++;
	while (*src != del && *src != '\0')
	{
		src++;
		len++;
	}
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		ft_error();
	src -= len;
	ft_strlcpy(*dst, src, len + 1);
	return ((char *)(src + len));
}

void	check_is_empty_string(const char *string)
{
	while (*string == ' ')
		string++;
	if (*string == '\0')
		ft_error();
}

char	**ft_split(const char *s, char c)
{
	char	**table;
	int		word_count;
	int		idx;

	check_is_empty_string(s);
	idx = 0;
	word_count = ft_count_words(s, c);
	table = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (table == 0)
		ft_error();
	while (idx < word_count)
	{
		s = ft_alloc_string(&table[idx], s, c);
		idx++;
	}
	table[word_count] = 0;
	return (table);
}
