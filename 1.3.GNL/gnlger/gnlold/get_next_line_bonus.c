/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:15:15 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/12/15 20:29:23 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new_line(char *storage)
{
	char	*line;
	int		len;

	len = 0;
	while (storage[len] != '\n' && storage[len] != '\0')
		len++;
	if (storage[len] == '\0')
	{
		return (NULL);
	}
	line = ft_substr(storage, len + 1, ft_strlen(storage) - len);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	storage[len + 1] = '\0';
	return (line);
}

char	*readbuf(int fd, char *storage, char *buffer)
{
	int		rid;
	char	*temp;

	rid = 1;
	while (rid > 0)
	{
		rid = read(fd, buffer, BUFFER_SIZE);
		if (rid == -1)
		{
			free(storage);
			return (NULL);
		}
		else if (rid == 0)
			break ;
		buffer[rid] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;
	char		*buff;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		return (NULL);
	}
	line = readbuf(fd, storage[fd], buff);
	free(buff);
	if (!line)
		return (NULL);
	storage[fd] = new_line(line);
	return (line);
}
