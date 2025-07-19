#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char	*excess;
	char		*buffer;
	char		*line;
	int			count;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	if (!excess)
		excess = ft_strdup("");	
	buffer[BUFFER_SIZE] = '\0';
	while(1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == 0)
			break ;
		else if (count == -1)
			return(free_all(buffer, excess));//NULL olmayanlar freelensin sonra return NULL versin.
		excess = ft_strjoin(excess, buffer);//eski excess ve buffer freelensin.
		count = ft_strchr(excess);// '\n' bulup i döndürsün. count'un işi bitmedi mi yazsın üzerine yeni değişşkene gerek yok.
		if (count)//'\n'bulduysak
		{
			line = ft_range(excess, 0, count, 0); // flag yerine line 0 dan başlamıyor mu onu da kullanabilirim..
			excess = ft_range(excess, count + 1, ft_strlen(excess), 1);// excess static ya başka bi fonksiyonda değişince değişir mi? öyleyse ilkinde ayırabilirim zaten.
			return (line);
		}
	}
	return (excess);//count 0 dönerse ve içeride kalan varsa return et yoksa boşver zaten.
}
