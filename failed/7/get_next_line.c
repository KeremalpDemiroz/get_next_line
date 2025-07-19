//read ile dosyayı oku ve static değişkene yaz
//static değişkende \n var mı
// varsa \n e kadar ve sonrası olarak ayır.
//
#include "get_next_line.h"

static int	find_newline(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*read_file(int fd, char *storage)
{
	char	*buffer;
	ssize_t	read_count;

	read_count = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (find_newline(storage) < 0 && read_count > 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(storage);
			storage = NULL;
			break ;
		}
		buffer[read_count] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}


char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	storage = read_file(fd, storage);
	if (!storage || storage[0] == '\0')
	{
		free(storage);
		storage = NULL;
		return(NULL);
	}
	return (line_and_storage(&storage));
}
