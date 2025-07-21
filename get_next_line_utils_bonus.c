/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:16:46 by kedemiro          #+#    #+#             */
/*   Updated: 2025/07/21 16:35:22 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)tmp)[i] = 0;
		i++;
	}
	return (tmp);
}

char	*ft_range(char *storage, int start, int end, int flag)
{
	char	*range;
	int		i;

	i = 0;
	range = ft_calloc(end - start + 2, sizeof(char));
	if (!range)
		return (NULL);
	while (start <= end)
	{
		range[i] = storage[start];
		start++;
		i++;
	}
	range[i] = '\0';
	if (flag)
		free(storage);
	return (range);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		size;
	int		i;

	i = 0;
	if (!str)
		size = 0;
	else
		size = ft_strlen(str);
	dup = ft_calloc(size + 1, sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *storage, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!storage || !buffer)
		return (ft_strdup(""));
	join = ft_calloc(ft_strlen(storage) + ft_strlen(buffer) + 1, sizeof(char));
	if (!join)
		return (NULL);
	while (storage[i])
	{
		join[i] = storage[i];
		i++;
	}
	while (buffer[j])
	{
		join[i + j] = buffer[j];
		j++;
	}
	join[i + j] = '\0';
	free(storage);
	return (join);
}
