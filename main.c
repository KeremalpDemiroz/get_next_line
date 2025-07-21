#include <fcntl.h>
#include <stdio.h>	
#include "get_next_line.h"

int main()
{
	char *line;

	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("dosya okunamadi");
		return (0);
	}
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			printf("\n%s", line);
		else
			printf("%s", line);
		if (!line)
			return (0);
		free(line);
	} 
	free(line);
	close(fd);
	return (0);
}