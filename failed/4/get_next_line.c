#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*excess;
	char		*buffer;
	char		*line;
	int			count;
	int			index;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == 0)
			break;
		excess = ft_strjoin(excess, buffer);
		if (count == -1)
			return (free(excess), NULL);
		index = ft_strchr(excess);
		if (index)
		{
			line = ft_range(excess, 0, index, 0);
			excess = ft_range(excess, index +1, ft_strlen(excess), 1);
			return (line);
		}
		else
			excess = ft_range(excess, 0, ft_strlen(excess), 1);
	}
	return (excess);
}
