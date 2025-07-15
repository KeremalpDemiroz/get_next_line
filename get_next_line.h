#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LİNE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 64
char	*get_next_line(int fd);

#endif