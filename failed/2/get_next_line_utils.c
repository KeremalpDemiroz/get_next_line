#include "get_next_line.h"

char	*line_or_excess(char *s1, char *s2, const char *buf, int i, int sw)
{
	char	*tmp;
	int		c_buf;
	int		j;
	int		i;

	i = 0;
	j = 0;
	c_buf = ft_strlen(buf);
	tmp = s2;
	if (sw)
	{
		s2 = malloc(sizeof(char) * (c_buf - i));
		s1 = malloc(sizeof(char) * (i + 2));
		if (!s2 || !s1)
			return (NULL);
		s1[i + 2] = '\0';
		while (j <= i)
			s1[j] = buf[j++];
		while (j < c_buf)
		{
			s2[i] = buf[j++];
			i++;
		}
		return (s1);
	}
	else
		s2 = ft_strjoin(s2, buf);
	return (s2);
	free(tmp);
}
// 	index	0	1	2	3	4	5	6	7	8	9	10	11	12	13
// 	buffer	m	e	r	h	a	b	a	\n	d	u	n	y	a	\0
// 	line:	m	e	r	h	a	b	a	\n	\0
//	excess	d	u	n	y	a	\0