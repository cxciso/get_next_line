#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoinx(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	result = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	result[i] = '\0';
	return (result);
}

int	ft_strchrx(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dest;
	int		size;

	size = ft_strlen((char *)s1) + 1;
	dest = (char *)malloc(sizeof(char) * size);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substrx(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*result;

	i = 0;
	j = 0;
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result || !s)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len && s[i])
		{
			result[j] = s[i];
			j++;
		}
		i++;
	}
	if (start > 0)
		free(s);
	result[j] = '\0';
	return (result);
}
