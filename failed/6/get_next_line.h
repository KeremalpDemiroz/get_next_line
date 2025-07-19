#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <stdlib.h>
# include <unistd.h>

char	*line_and_storage(char **storage, int index);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *str, char *buffer, int read_count);
char	*get_next_line(int fd);
char	*ft_strdup(char	*str);
int		ft_strlen(char	*str);


#endif