/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:04:37 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/12/15 23:14:21 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str;
	char	*str1;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	str = get_next_line(fd1);
	str1 = get_next_line(fd2);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd1);
	}
	while (str1)
	{
		printf("%s", str1);
		free(str1);
		str1 = get_next_line(fd2);
	}
	printf("%s", str);
	printf("%s", str1);
	close(fd1);
	close(fd2);
	return (0);
}
/*#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac < 2)
		fd = 0;
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}*/
