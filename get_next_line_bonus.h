/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:59:43 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/03 12:14:21 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);
char	*ft_strdup(char *s);
int	ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *stash, char *buffer);
int ft_strchr(char *s, int c);



#endif 