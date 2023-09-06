/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:57:08 by feberman          #+#    #+#             */
/*   Updated: 2023/05/30 11:46:59 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
int		ft_line_complete(char *line);
char	*ft_join(char *s1, char *s2);

char	*ft_get_line_from_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\0' || buffer[i] == -1)
			i++;
		else
		{
			j = 0;
			while (buffer[i + j] != '\n' && buffer[i + j] != -1 \
				&& i + j < BUFFER_SIZE)
				j++;
			out = ft_substr_gnl(buffer + i, 0, j + 1);
			if (out == 0)
				return (0);
			j += i;
			while (i <= j)
				buffer[i++] = '\0';
			return (out);
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[__FD_SETSIZE][BUFFER_SIZE];
	char		*line;
	int			r;

	if (fd < 0 || fd >= __FD_SETSIZE)
		return (0);
	line = ft_get_line_from_buffer(buffer[fd]);
	while (!ft_line_complete(line))
	{
		r = read(fd, buffer[fd], BUFFER_SIZE);
		if (r > 0)
		{
			if (r < BUFFER_SIZE)
				buffer[fd][r] = -1;
			line = ft_join(line, ft_get_line_from_buffer(buffer[fd]));
		}
		else if (r == 0)
			return (line);
		else
		{
			free(line);
			return (0);
		}
	}
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("test", O_RDONLY);
	int	fd2 = open("test2", O_RDONLY);
	char	*line;
	char	*line2;
	int	i = 0;

	printf("Buffersize: %i\n", BUFFER_SIZE);
	while (i < 10)
	{
		printf("%s",get_next_line(0));
		i++;
	}
}*/
