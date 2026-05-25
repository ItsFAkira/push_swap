/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:11:21 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/08 17:41:56 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int		len;
	long	num;

	len = 0;
	num = n;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*word;
	int		len;
	long	num;

	num = n;
	len = get_len(n);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0';
	len--;
	if (num < 0)
	{
		word[0] = '-';
		num = -num;
	}
	if (num == 0)
		word[0] = '0';
	while (num > 0)
	{
		word[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (word);
}
