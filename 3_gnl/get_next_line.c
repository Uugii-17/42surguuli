#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

// Helper to find '\n' (re-implemented or from libft)
static char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

// _fill_line_buffer: Accumulates read data into the growing buffer (left_c/line_buffer)
// until a '\n' is found or EOF/error.
// Uses ft_strjoin to append, ft_strdup if starting fresh, ft_strchr to check for '\n'.
static char *_fill_line_buffer(int fd, char *left_c, char *buffer)
{
    ssize_t bytes_read;
    char    *tmp;

    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(left_c, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(left_c);
            return (NULL);
        }
        buffer[bytes_read] = '\0';  // Null-terminate for string funcs
        if (!left_c)
            left_c = ft_strdup(buffer);  // First append: duplicate buffer
        else
        {
            tmp = ft_strjoin(left_c, buffer);  // Append new read to existing
            free(left_c);
            left_c = tmp;
        }
    }
    return (left_c);
}

// _set_line: Extracts the line up to (and including) '\n' or full buffer at EOF.
// Replaces '\n' with '\0' if present, returns the line via ft_substr/ft_strdup.
// Updates leftover (remainder after '\n') for next call.
static char *_set_line(char *line_buffer)
{
    char    *newline_pos;
    char    *leftover;
    char    *line;

    if (!line_buffer || !*line_buffer)
        return (NULL);
    newline_pos = ft_strchr(line_buffer, '\n');
    if (newline_pos)
    {
        *newline_pos = '\0';  // Terminate line at '\n'
        line = ft_strdup(line_buffer);  // Line without '\n'
        leftover = ft_strdup(newline_pos + 1);  // Remainder after '\n'
    }
    else
    {
        line = ft_strdup(line_buffer);  // Full buffer is the last line
        leftover = NULL;
    }
    free(line_buffer);
    return (leftover);  // New static value
}

// Main function
char *get_next_line(int fd)
{
    static char *left_c;        // Persistent leftover across calls
    char        *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    line = _fill_line_buffer(fd, left_c, buffer);  // Accumulate until '\n' or EOF
    free(buffer);
    if (!line)
    {
        left_c = NULL;
        return (NULL);
    }
    left_c = _set_line(line);  // Extract line, update leftover
    if (!line || !*line)       // Empty line or EOF with nothing left
    {
        free(line);
        return (NULL);
    }
    return (line);             // Caller must free this
}
/*char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}
char	*new_line(char *storage)
{
	char	*line;
	char	*str;
	int		len;

	str = ft_strchr(storage, '\n');
	len = (str - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}
char	*readbuf(int fd, char *storage)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (rid > 0 && !ft_strchr(buffer, '\n'))
	{
		rid = read (fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (ft_free(&storage));
	return (storage);
}
char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = readbuf (fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (ft_free(&storage));
	storage = clean_storage(storage);
	return (line);
}*/