/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:58:18 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/06 16:12:47 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(char *stash, int fd)
{
	int		bytes_read;
	char	*buffer;

	if (stash == NULL)
		stash = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && stash[0] == 0))
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoinfree(stash, buffer);
		free(buffer);
	}
	buffer = NULL;
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*result;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	result = ft_substr(stash, 0, i);
	return (result);
}

static char	*rest_of_line(char *stash)
{
	int		i;
	char	*result;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	result = ft_substr(stash, i, ft_strlen(stash));
	free(stash);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_line(stash[fd], fd);
	line = extract_line(stash[fd]);
	stash[fd] = rest_of_line(stash[fd]);
	if (stash[fd] && stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
