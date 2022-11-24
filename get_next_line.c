/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:36 by dcarrilh          #+#    #+#             */
/*   Updated: 2022/11/23 15:58:08 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*firstline(char *file)
{
	size_t	size;
	char	*line;

	size = 0;
	if (!file)
		return (0);
	while (file[size] != '\n' && file)
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (0);
	if (file[size] == '\n' || file[size] == '\0')
		ft_strlcpy(line, file, size+1);
	if (file[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

static char	*newfile(char *file)
{
	size_t	size;
	char	*resto;
	
	size = 0;
	while (file[size] != '\n' && file)
		size++;
	if (!file[size])
	{
		free(file);
		return (0);
	}
	resto = (char *)malloc(sizeof(char) * (ft_strlen(file) - size + 1));
	size++;
	if (!resto)
		return (0);
	resto = ft_substr(file, size, ft_strlen(file));
	free(file);
	return (resto);
}

static char	*inifile(int fd, char *file)
{
	char	*buff;
	ssize_t readbytes;
	
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	readbytes = 1;
	while (!ft_strchr(file, '\n') && readbytes >= 0)
	{
		readbytes = read(fd, buff, BUFFER_SIZE);
		if (readbytes < 0)
		{
			free(buff);
			return(0);
		}
		buff[readbytes] = '\0';
		file = ft_strjoin(file, buff);
	}
	free(buff);
	return (file);
}		

char	*get_next_line(int fd)
{
	static char	*file;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	file = inifile(fd, file);
	if (!file)
		return (0);
	line = firstline(file);
	file = newfile(file);
	return (line);
}
	
/*#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 17)
	{
		line = get_next_line(fd1);
		printf("line [%d]: %s\n", i, line);
		free(line);

		i++;
	}
	close(fd1);
	return (0);
}*/
