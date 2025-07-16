#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
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

char	*ft_strdup(const char *s)
{
	char	*tmp;
	int		j;

	tmp = malloc(ft_strlen(s) + 1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	char	*res;
	int		i;
	int		j;


	j = 0;
	i = 0;
	tmp = s1;
	if (!s1)
		s1 = ft_strdup("");
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
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
	free (tmp);
	return (res);
}
char	*ft_range(char *s1, int start, int end, int flag)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	tmp = s1;
	res = malloc(sizeof(char) * (end - start) + 1);
	while (i <= end - start)
	{
		res[i] = (s1 + start)[i];
		i++;
	}
	res[i] = '\0';
	if (flag)
		free(tmp);
	return (res);
}
// int main()
// {
// 	char *s =  ft_strdup("merhaba");
// 	char *d = ft_strdup(" nasilsin");
// 	char *res = ft_strjoin(s,d);
// }