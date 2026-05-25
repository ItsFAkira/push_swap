/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:49:37 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/07 11:52:19 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
		{
			return (1);
		}
		j++;
	}
	return (0);
}

static int	len_size(int *start, int *end, char const *s1, char const *set)
{
	*start = 0;
	*end = ft_strlen(s1) - 1;
	while (s1[*start] && in_set(s1[*start], set))
		(*start)++;
	while (*end >= *start && in_set(s1[*end], set))
		(*end)--;
	return (*end - *start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;
	int		i;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = len_size(&start, &end, s1, set);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
