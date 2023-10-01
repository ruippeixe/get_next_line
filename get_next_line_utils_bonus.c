#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		if (s2[i] == '\n')
			break ;
		i++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

int	clear_and_check_end(char *buffer_line)
{
	int	line_ended;
	int	i;
	int	j;

	i = 0;
	j = 0;
	line_ended = 0;
	while (buffer_line[i])
	{
		if (line_ended)
			buffer_line[j++] = buffer_line[i];
		if (buffer_line[i] == '\n')
			line_ended = 1;
		buffer_line[i] = '\0';
		i++;
	}
	return (line_ended);
}
