/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:08:06 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/12/15 18:06:33 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd1 = open("test1.txt", O_RDONLY);
	char *str = get_next_line(fd1);
	while (str)
	{
		printf("%s", str);
        free(str);
        str = get_next_line(fd1);
	}
	printf("%s", str);
    close(fd1);
	return (0);
}
