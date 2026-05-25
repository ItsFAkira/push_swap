/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:03:40 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/06 18:58:46 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendest;
	size_t	i;

	lensrc = 0;
	lendest = 0;
	i = 0;
	while (src[lensrc] != '\0')
		lensrc++;
	while (dst[lendest] != '\0' && lendest < size)
		lendest++;
	if (size <= lendest)
		return (size + lensrc);
	while (src[i] != '\0' && (lendest + i < size - 1))
	{
		dst[lendest + i] = src[i];
		i++;
	}
	dst[lendest + i] = '\0';
	return (lensrc + lendest);
}
