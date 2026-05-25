/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonfe2 <antonfe2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:35:42 by antonfe2          #+#    #+#             */
/*   Updated: 2026/05/25 12:54:32 by antonfe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
 * Stores the content inside the stash until a newline or EOF is reached.
 * Each read buffer is concatenated to the existing stash.
 * Returns the updated stash or NULL if an error occurs.
 */
static char	*fill_stash(char *stash, int fd)
{
	int		bytes;
	char	*buffer;
	char	*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while ((!stash || stash_chr(stash, '\n') == NULL) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = stash;
		stash = stashjoin(stash, buffer);
		free(tmp);
	}
	free(buffer);
	return (stash);
}

/*
 * Reads and returns the next line (until \n) from a file descriptor.
 * Makes the rest of the file descriptor into the new stash.
 * Returns NULL when there is nothing left to read or an error occurs.
 *
 * The only difference between the mandatory part of the project is that stash
 * must read more than 1 fd.
 *
 * 1024 is used for size of stash because the computer can't read more than
 * that number of files.
 */
char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*tmp;

	if (fd > 1024 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = fill_stash(stash[fd], fd);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = copy_line(stash[fd]);
	tmp = copy_next_line(stash[fd]);
	free(stash[fd]);
	stash[fd] = tmp;
	return (line);
}
