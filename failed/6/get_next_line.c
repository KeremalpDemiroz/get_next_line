#include "get_next_line.h"

static int	ft_strchr(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			return (i);	
		i++;
	}
	return (0);
}

static void	*free_all(char *s1, char *s2)
{
	if (s1 != NULL)
		free (s1);
	if (s2 != NULL)
		free (s2);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*line;
	ssize_t			read_count;
	int			index;

	index = 0;
	read_count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (index == 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == 0)
			break;
		if (read_count == -1)
			return (free_all(buffer, storage));
		storage = ft_strjoin(storage, buffer, read_count);
		index = ft_strchr(storage);
	}
	if (index != 0)
		return (line_and_storage(&storage, index));
	else
		return (storage);
}
