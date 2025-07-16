#include "get_next_line.h"

int	ft_strchr(const char *s, int c)//index değeri return ediyor artık bulursa, bulamazsa 0
{
	int		i;
	char	*tmp;

	tmp = (char *)s;
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	j;

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


char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	total_size;
	size_t	i;
	size_t	j;
	char	*str;
	char	*tmp;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	tmp = s1;
	str = malloc(total_size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(tmp);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*temp;
	size_t			temp_len;

	temp_len = 0;
	i = 0;
	if (start >= ft_strlen(s))
	{
		temp = ft_strdup("");
		return (temp);
	}
	if (ft_strlen(s) - start < len)
		temp_len = ft_strlen(s) - start;
	else
		temp_len = len;
	temp = malloc(temp_len +1);
	if (!temp)
		return (NULL);
	while (i < temp_len && s[start + i] != '\0')
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

// int main()
// {
// 	char buffer[] = "merhaba \ndunya";
// 	int index = ft_strchr(buffer, '\n');
// 	char *res = ft_substr(buffer, 0, index +1);
// 	char *excess = ft_substr(buffer, index +1, ft_strlen(buffer));
// 	printf("%s\n", excess);
// 	printf("%s-", res);
// 	free(res);
// 	free(excess);
// }