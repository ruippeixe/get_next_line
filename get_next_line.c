#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (clear_and_check_end(buffer))
			break ;
		if (read(fd, buffer, 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}

// int main()
// {
//   int fd;
//   char *line;
//   fd = open("file1.txt", O_RDONLY);

//   // line = get_next_line(fd);
//   // printf("%s", line);

//   while ((line = get_next_line(fd)) != NULL)
// 		printf("result: %s", line);
// 	printf("\n");

//   close(fd);
// }
