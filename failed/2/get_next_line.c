#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*excess;
	char		*line;
	char		*buffer;
	int			count;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	count = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	if (!buffer)
		return (NULL);
	while (count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		while (buffer)
		{
			if (buffer[i] != '\n' && buffer[i])
				i++;
			else
				flag = 1;
			buffer++;
		}
		if (!flag)
			excess = line_or_excess(line, buffer, i, flag);
		else
			line = line_or_excess(line, buffer, i, flag);
		if (count == 0)
			break;
	}
	return (line);
}
