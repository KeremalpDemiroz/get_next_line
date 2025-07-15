#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, nmemb * size);
	return (tmp);
}

int	ft_strlen(const char *buffer)
{
	int j;

	j = 0;
	while (buffer[j])
		j++;
	return (j);
}

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	j;

	tmp = ft_calloc(ft_strlen(s) + 1,1);
	if (!tmp)
		return (NULL);
	j = 0;
	while (s[j] != '\0')
	{
		tmp[j] = s[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
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
	excess = ft_calloc(ft_strlen(excess) + ft_strlen(buffer + j) + 1, 1);
	if (!excess)
		return (NULL);
	while (*(excess + i))
		excess[i++]; 
	while (*(buffer + j))
	{
		excess[i] = buffer[j];
		j++;
		i++;
	}
	free(temp);
	return (excess);
}

int main()
{
	int i = 0;
 	static char *excess = NULL;
 	excess = ft_strdup("merhaba");
 	char *buffer = "selam dunya \n- nasilsinfdfdsf f sdf \nsd fsd fs";
 	excess = ft_get_excess(excess, buffer);
	printf("%s\n", excess);
	free(excess);
}
