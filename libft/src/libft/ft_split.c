/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:25:38 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/08 18:17:44 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static char	*extract_word(char const *s, char c, int *ptr)
{
	int		size;
	int		startword;
	int		j;
	char	*word;

	j = 0;
	startword = 0;
	while (s[*ptr] == c)
		(*ptr)++;
	startword = *ptr;
	while (s[*ptr] != c && s[*ptr])
		(*ptr)++;
	size = *ptr - startword;
	word = malloc((size + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (j < size)
	{
		word[j] = s[startword + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	free_arr(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		ptr;

	if (!s)
		return (NULL);
	ptr = 0;
	words = (count_words(s, c));
	i = 0;
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < words)
	{
		arr[i] = extract_word(s, c, &ptr);
		if (!arr[i])
		{
			free_arr(arr, i);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
