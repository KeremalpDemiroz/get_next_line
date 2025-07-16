#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 64

char	*get_next_line(int fd);
char	*ft_range(char *s1, int start, int end, int flag);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
int		ft_strchr(char *s1);


#endif