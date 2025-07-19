#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = -1;
	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	while (str[++i])
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *excess, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	j = -1;
	join = malloc(ft_strlen(excess) + ft_strlen(buffer) + 1);
	if (!join)
		return (NULL);
	while (excess[++i])
		join[i] = excess[i];
	while (buffer[++j])
		join[i+ j] = buffer[j];
	join[i + j] = '\0';
	free(excess);
	return (join);
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

char	*read_file(int fd, char *excess)
{
	char	*buffer;
	ssize_t	count;

	count = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (find_newline(excess) < 0 && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(excess);
			excess = NULL;
			break ;
		}
		buffer[count] = '\0';
		excess = ft_strjoin(excess, buffer);
	}
	free(buffer);
	if (count == 0 && !excess)
		return (NULL);
	return (excess);
}

char	*ft_range_and_free(char *excess, int start, int end, int flag)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i] = excess[start];
		start++;
	}
	res[start] = '\0';
	if (flag)
	{
		free(excess);
		excess = NULL;
	}
	return (res);
}

// char	*line_and_excess(char  **excess)
// {
// 	char	*res;
// 	char	*tmp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = -1;
// 	tmp = *excess;
// 	while (tmp[i] != '\n')
// 		i++;
// 	res = malloc(i + 2);
// 	if(!res)
// 		return (NULL);
// 	while (++j <= i)
// 		res[j] = tmp[j];
// 	res[j] = '\0';
// 	*excess = ft_strdup(tmp + i+1);
// 	free(tmp);
// 	return (res);
// }

char	*get_next_line(int  fd)
{
	static char	*excess;
	int			index;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!excess)
		excess = ft_strdup("");
	excess = read_file(fd, excess);
	if (!excess || excess[0] == '\0')
	{
		free(excess);
		excess = NULL;
		return (NULL);
	}
	index = find_newline(excess);
	if (index != -1)
	{
		// line = line_and_excess(&excess);
		line = ft_range_and_free(excess, 0, index, 0);
		excess = ft_range_and_free(excess, index + 1, ft_strlen(excess), 1);
		return (line);
	}
	else
	{
		printf("excess : %s\n", excess);
		return (excess);
	}
}

int main()
{
    int     fd;
    char    *line;
    int     line_count;

    // --- Dosya Tanımlayıcısını (fd) Belirleme --//
        // Komut satırından bir dosya adı verildi, onu açalım.
        fd = open("test.txt", O_RDONLY);
        if (fd == -1)
        {
            perror("Dosya açma hatası");
            return (1);
        }
        printf("--- '%s' dosyasından okunuyor ---\n", "test.txt");
    // --- get_next_line'ı Döngüde Çağırma ---
    line_count = 1;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            printf("\n--- Okuma bitti (get_next_line NULL döndürdü) ---\n");
            break; // Döngüden çık
        }

        // Okunan satırı ve satır numarasını yazdır
        printf("Satir %d: -%s-\n", line_count, line);
        free(line);
        // GNL'den dönen ve malloc ile ayrılmış olan satırı serbest bırak
        line_count++;
    }

    // Eğer bir dosya açtıysak, kapatmayı unutmayalım.
    if (fd > 0)
    {
        close(fd);
    }
    return (0);
}