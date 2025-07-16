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

int main()
{
	char buffer[] = "merhaba \n dunya";
	int index = ft_strchr(buffer, '\n');
	char *res = ft_substr(buffer, 0, index);

}