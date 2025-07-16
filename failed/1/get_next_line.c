#include "get_next_line.h"
//"merhaba";

int	ft_strlen(const char *buffer)
{
	int	i;

	i = 0;
	while (*buffer)
		i++;
	return (i);
}
char	*ft_get_excess(char *excess, char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = excess;
	while (*(buffer + j) != '\n')
		j++;
	if (j == ft_strlen(buffer))
		j = 0;
	else
		j++;
	excess = malloc(ft_strlen(excess) + ft_strlen(buffer + j) + 1);
	if (!excess)
		return (NULL);
	while (*(excess + i))
		excess[i++]; 
	while (*(buffer + j)
	{
		excess[i+j] = buffer[j];
		j++;
	}
	free(temp);
	return (excess);
}

char *get_next_line(int fd)
{
	static char	*excess;
	char		*buffer;
	ssize_t		count;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	count = read(fd, buffer, BUFFER_SIZE);
	excess = ft_get_excess(excess, buffer);
}
