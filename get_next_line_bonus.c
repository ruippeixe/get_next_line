#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= 1024)
		return (NULL);
	line = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (clear_and_check_end(buffer[fd]))
			break ;
		if (read(fd, buffer, 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}
