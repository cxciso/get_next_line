#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # define BUFFER_SIZE 5

size_t	ft_strlen(const char *s);
char	*ft_strjoinx(char *s1, char *s2);
int		ft_strchrx(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	*ft_substrx(char *s, unsigned int start, size_t len);

#endif