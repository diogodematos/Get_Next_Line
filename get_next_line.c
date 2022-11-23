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

char	*firstline(char *file)
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

char	*newfile(char *file)
{
	size_t	size;
	char	*resto;
	
	size = 0;
	if (!file)
		return (0);
	while (file[size] != '\n' && file)
		size++;
	resto = (char *)malloc(sizeof(char) * (ft_strlen(file) - size) + 1);
	size++;
	if (!resto)
		return (0);
	resto = ft_substr(file, size, ft_strlen(file) - size);
	return (resto);
}
	
int	main()
{
	printf("%s", firstline("amanha\nejegfisu\nhsdfhs"));
	printf("%s", newfile("amanha\nejegfisu\nhgsjhf"));
	return (0);
}	




	

/*char	*get_next_line(int fd)
{
*/
