#include "get_next_line.h"

char	*get_next_line(int  fd)
{
	static char *excess;
	char	*buffer;
	int		count;
	int		index;
	char	*line;

	count = 1;
	if (!excess)
		excess = ft_strdup("");//bunu kullanmamak için strjoin NULL ile çalışabilmeli
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (count)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (free(buffer), NULL);
		if (count == 0)
			break ;
		index = ft_strchr(buffer, '\n');
		if (!index)
		{
			excess = ft_strjoin(excess, buffer); //içte char *temp = excess; free(temp) olmalı
			free (buffer);
		}
		else
		{
			line = ft_substr(buffer, 0, index + 1); // i bulunan \n indexi olmalı strchr modifiye int return için modifiye et // + 1 \n dahil olması için
			excess = ft_strjoin(excess, buffer + index + 1);
			free (buffer); // buffer + i +1 adresi ile kalan kısmı ile excess birleştirilebilir bence
			return (line);
		}
	}
	return (excess);
}

int main()
{
	char *line;
	int i = 0;
	int fd = open("test.txt", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	close (fd);
}
