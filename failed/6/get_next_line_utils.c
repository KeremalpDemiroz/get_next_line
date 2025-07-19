#include "get_next_line.h"

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
		((unsigned char *)tmp)[i] = '\0';
		i++;
	}
	return (tmp);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*str)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		str = ft_strdup("");
	res = ft_calloc(ft_strlen(str) + ft_strlen(buffer) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		res[i + j] = buffer[j];
		j++;
	}
	res[i + j] = '\0';
	free(str);
	return (res);
}

char	*line_and_storage(char **storage, int index)
{
	char	*temp;
	char	*line;
	int		i;

	i = 0;
	temp = *storage;
	line = ft_calloc(index + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i <= index)
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	*storage = ft_strdup(temp + index + 1);
	free(temp);
	return (line);
}
