/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:56:45 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/22 12:55:08 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
 * Searches for the first occurrence of character c in the stash string.
 * Returns a pointer to the first matching character if found,
 * or NULL if the character is not present.
 * If c is '\0', returns a pointer to the end of the string.
 *
 * Basically, a strchr function.
 */
char	*stash_chr(char *stash, int c)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == (char)c)
		{
			return ((char *)stash + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)stash + i);
	return (NULL);
}

/*
 * Concatenates the current stash with the newly read buffer
 * and returns a newly allocated string containing both.
 * If stash is NULL, it is treated as an empty string.
 * The result is always dynamically allocated.
 *
 * Basically, a strjoin function.
 */
char	*stashjoin(char *stash, char *buffer)
{
	char	*ptr;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	if (!stash)
		stash = "";
	ptr = malloc((search_n_len(stash, 1) + search_n_len(buffer, 1) + 2)
			* sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i])
	{
		ptr[i] = stash[i];
		i++;
	}
	while (buffer[j])
		ptr[i++] = buffer[j++];
	ptr[i] = '\0';
	return (ptr);
}

/*
 * Returns a length based on the mode selected:
 * - If strlen == 0: returns the length up to and including
 *   the first newline character (if present).
 * - If strlen != 0: returns the full length of the string.
 * Used to simplify line extraction and memory allocation
 * in get_next_line helpers.
 */
int	search_n_len(char *s, int strlen)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (strlen == 0)
	{
		while (s[i] != '\0' && s[i] != '\n')
			i++;
		if (s[i] == '\n')
			i++;
	}
	else
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

/*
 * Extracts and returns the next line from the given string.
 * The line includes characters up to and including the first
 * newline character, if present. If no newline exists, the
 * entire string is returned as a single line.
 */
char	*copy_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	line = malloc((search_n_len(s, 0) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
 * Creates and returns a new string containing the
 * remaining content after the extracted line.
 * This updated stash will be used in the next
 * call to get_next_line.
 */
char	*copy_next_line(char *s)
{
	int		i;
	int		j;
	char	*after_line;

	if (!s)
		return (NULL);
	i = search_n_len(s, 0);
	j = 0;
	while (s[i + j] != '\0')
		j++;
	after_line = malloc((j + 1) * sizeof(char));
	if (!after_line)
		return (NULL);
	j = 0;
	while (s[i] != '\0')
	{
		after_line[j] = s[i];
		j++;
		i++;
	}
	after_line[j] = '\0';
	return (after_line);
}
