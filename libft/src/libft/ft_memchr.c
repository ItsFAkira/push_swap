/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:35:52 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/06 18:29:42 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;
	unsigned char		ch;

	i = 0;
	src = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (src[i] == ch)
			return ((void *)src + i);
		i++;
	}
	return (NULL);
}
