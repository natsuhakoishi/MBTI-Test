#ifndef GNL_H
# define GNL_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t size);

#endif
