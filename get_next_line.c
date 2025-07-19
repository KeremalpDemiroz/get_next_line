#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*tmp;
	int				i;

	i = 0;
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)tmp)[i] = 0;
		i++;
	}
	return (tmp);
}

int	find_newline(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		size;
	int		i;

	i = 0;
	if (!str)
		size = 0;
	else
		size = ft_strlen(str);
	dup = ft_calloc(size + 1, sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++; 
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!storage || !buffer)
		return (ft_strdup(""));
	join = ft_calloc(ft_strlen(storage) + ft_strlen(buffer) + 1, sizeof(char));
	if (!join)
		return (NULL);
	while (storage[i])
	{
		join[i] = storage[i];
		i++;
	}
	while (buffer[j])
	{
		join[i + j] = buffer[j];
		j++;
	}
	join[i + j] = '\0';
	free((void *)storage);
	return (join);
}

char	*ft_range(char *storage, int start, int end, int flag)
{
	char	*range;
	int		i;

	i = 0;
	range = ft_calloc(end - start + 2, sizeof(char));
	if (!range)
		return (NULL);
	while (start <= end)
	{
		range[i] = storage[start];
		start++;
		i++;
	}
	range[i] = '\0';
	if (flag)
		free(storage);
	return (range);
}
//merhaba\n\n\n    merhaba\n    \n\n   


char	*read_file(int fd, char *storage)
{
	char	*buffer;
	ssize_t	count;
	count = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (find_newline(storage) < 0 && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free (buffer);
			storage = NULL;
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
	static char	*storage;
	char		*line;
	int			index;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	storage = read_file(fd, storage);
	index = find_newline(storage);
	if (index == -1)
	{
		if (*storage == '\0')
			return (NULL);
		line = storage;
		storage = NULL;
		return (line);
	}
	else
	{
		line = ft_range(storage, 0, index, 0);
		storage = ft_range(storage, index +1, ft_strlen(storage),1);
		return (line);
	}
}
int main()
{
	char *line;

	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("dosya okunamadi");
		return (0);
	}
	while(1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line && line[0] == '\n')
			printf("empty");
		if (!line)
			return (0);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}