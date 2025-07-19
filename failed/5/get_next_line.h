#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int	ft_strlen(char *s);
char	*ft_strdup(char *s);
void	*free_all(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_range(char *s1, int start, int end, int flag);
char	*get_next_line(int fd);
int	ft_strchr(char *s1);

#endif