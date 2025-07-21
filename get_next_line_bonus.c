/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:16:52 by kedemiro          #+#    #+#             */
/*   Updated: 2025/07/21 20:48:14 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*read_file(int fd, char *storage)
{
	char	*buffer;
	ssize_t	count;

	count = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	while (find_newline(storage) < 0 && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free (buffer);
			free (storage);
			return (NULL);
		}
		buffer[count] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[2048];
	char		*line;
	int			index;

	if (BUFFER_SIZE <= 0 || fd < 0 || !(storage[fd] = read_file(fd, storage[fd])))
		return (NULL);
	index = find_newline(storage[fd]);
	if (index == -1)
	{
		line = storage[fd];
		storage[fd] = NULL;
		if (*line == '\0')
		{
			free(line);
			return (NULL);
		}
		return (line);
	}
	else
	{
		line = ft_range(storage[fd], 0, index, 0);
		storage[fd] = ft_range(storage[fd], index + 1, ft_strlen(storage[fd]), 1);
		return (line);
	}
}
