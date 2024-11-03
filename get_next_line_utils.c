/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:58:09 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/03 12:06:15 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char    *result;
	int     i;
	int     j;

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

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;
    //Verification stash et buffer necessaire??
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
    free(stash);//necessaire pour la boucle de read_line
    //stash = NULL;
	return (result);
}

int ft_strchr(char *s, int c)// on renvoie int car ca sert de boolen pour le while , 0 = False 1 et + = True , ca sert a trouver l index du \n
{
	int	i; // je chercher \n et si je trouve j'envoie a l'index de \n

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (0);
}