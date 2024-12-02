#include "get_next_line.h"

char	*count_and_join(char *final, int fd)
{
	int		count;
	char	buf[BUFFER_SIZE + 1];

	count = 1;
	while (count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
		{
			free (final);
			return (NULL);
		}
		if (count == 0)
			return (final);
		buf[count] = '\0';
		if (final == NULL)
			final = ft_strdup(buf);
		else if (count > 0)
			final = ft_strjoinx(final, buf);
		if (ft_strchrx(final, '\n') >= 0)
			break ;
	}
	return (final);
}

char	*get_next_line(int fd)
{
	static char	*final = NULL;
	char		*sub;
	int			len;

	sub = NULL;
	if (final == NULL || ft_strchrx(final, '\n') == -1)
		final = count_and_join(final, fd);
	len = ft_strchrx(final, '\n');
	if (len >= 0)
	{
		sub = ft_substrx(final, 0, len + 1);
		final = ft_substrx(final, len + 1, ft_strlen(final) - len);
	}
	else if (final)
	{
		if (ft_strlen(final) > 0)
			sub = ft_strdup(final);
		free(final);
		final = NULL;
	}
	return (sub);
}
