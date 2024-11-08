/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:58:09 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/08 13:31:04 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	j = ft_strlen(s + start);
	if (j < len)
		len = j;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoinfree(char *stash, char *buffer)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	result = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (stash[i])
		result[k++] = stash[i++];
	j = 0;
	while (buffer[j])
		result[k++] = buffer[j++];
	result[k] = '\0';
	free(stash);
	return (result);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}
