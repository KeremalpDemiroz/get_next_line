#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\n')
			return (i);	
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

void	*free_all(char *s1, char *s2)
{
	if (s1 != NULL)
		free (s1);
	if (s2 != NULL)
		free (s2);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1 ) + 1);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	*ft_range(char *s1, int start, int end, int flag)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (end - start));
	while (i <= end - start)
	{
		res[i] = (s1 + start)[i];
		i++;
	}
	res[i] = '\0';
	if (flag)
		free(s1);
	return (res);
}
