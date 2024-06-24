/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocaio-re <ocaio-re@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:35:34 by ocaio-re          #+#    #+#             */
/*   Updated: 2024/06/24 14:35:39 by ocaio-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *dest)
{
	char	*buf;
	int		count_read;

	count_read = 1;
	while (nextline(dest) == 0 && count_read != 0)
	{
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		count_read = read(fd, buf, BUFFER_SIZE);
		if (count_read == 0)
		{
			free(buf);
			return (dest);
		}
		if (count_read == -1)
		{
			free(buf);
			free(dest);
			return (NULL);
		}
		dest = ft_strjoin(dest, buf);
		free(buf);
	}
	return (dest);
}

char	*clean_line(char *dest)
{
	char	*line;
	int		next;

	next = nextline(dest);
	if (next == 0)
		next = ft_strlen(dest);
	if (next == 0)
		return (NULL);
	line = ft_calloc(sizeof(char), (next + 1));
	if (!line)
	{
		free (dest);
		return (NULL);
	}
	ft_strlcpy(line, dest, next + 1);
	return (line);
}

char	*new_dest(char *dest)
{
	char	*new_dest;
	int		i;
	int		len;

	len = ft_strlen(dest);
	i = nextline(dest);
	if (i == 0 || len == 0)
	{
		free (dest);
		return (NULL);
	}
	new_dest = ft_calloc(sizeof(char), len - i + 1);
	if (!new_dest)
	{
		free(dest);
		return (NULL);
	}
	ft_strlcpy(new_dest, &dest[i], len - i + 1);
	free(dest);
	return (new_dest);
}

char	*get_next_line(int fd)
{
	static char		*dest;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest = read_line(fd, dest);
	if (!dest)
		return (NULL);
	line = clean_line(dest);
	dest = new_dest(dest);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;

    char *ptr;
    fd = open("test.txt", O_RDONLY);
    ptr = get_next_line(fd);
    printf("%s", ptr);
    free(ptr);

    ptr = get_next_line(fd);
    printf("%s", ptr);
    free(ptr);

    ptr = get_next_line(fd);
    printf("%s", ptr);
    free(ptr);
}