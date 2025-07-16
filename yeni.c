#include "get_next_line.h"

char	*get_next_line(int  fd)
{
	static char *excess;
	char	*buffer;
	int		count;
	int		index;
	char	*line;

	count = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	excess = ft_strdup("");//bunu kullanmamak için strjoin NULL ile çalışabilmeli
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == 0)
			return (excess);
		index = ft_strchr(buffer, '\n');
		if (!index)
			excess = ft_strjoin(excess, buffer);//içte char *temp = excess; free(temp) olmalı
		else
		{
			line = ft_substr(buffer, 0, index); // i bulunan \n indexi olmalı strchr modifiye int return için modifiye et
			excess = ft_strjoin(excess, buffer + index); // buffer + i adresi ile kalan kısmı ile excess birleştirilebilir bence
			return (line);
		}
	}
}