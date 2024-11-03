/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:58:18 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/03 12:15:29 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *read_line(char *stash, int fd)
{
    int bytes_read; //nbre de caractere lu
    char    *buffer; // stocke temporairement les caracteres lues
    if (stash == NULL) //s'il n'y a rien dans stash
        stash = ft_strdup("");
    bytes_read = 1; // 1 car sinon il ne va pas rentrer dans la boucle juste apres
    while (bytes_read > 0 && !ft_strchr(stash, '\n'))// si le nombre de caractere lu est positif et que je ne trouve pas \n dans la stash, je continue le while
    {
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
            return (NULL);
        bytes_read = read (fd, buffer, BUFFER_SIZE);// je lis et j'envoie dans buffer les caracteres lues
        if (bytes_read == -1 || (bytes_read == 0 && stash[0] == 0)) // 0 = rien a lire 
        {
            free (stash);
            free (buffer);
            return (NULL);
        }
        
        buffer[bytes_read] = '\0';//ou 0  j'enleve les caracteres lues afin de pouvoir accueillir les caracteres a lire suivant
        stash = ft_strjoin(stash, buffer);// je rajoute les caracteres lues par buffer dans stash 
        free (buffer);// je free buffer a chaque fois 
    }
    buffer = NULL;
    return (stash);
}

static  char *extract_line(char *stash)
{
    int i;
    char *result;

    i = 0;
    if (!stash)
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;// car substr prend la len et non l index 
    result = ft_substr(stash, 0, i);// je recupere stash jusqu a \n 
    return (result);
}

static char *clean_line(char *stash)
{
    int i;
    char *result;

    i = 0;
    if (!stash)
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    //que se passe t il si i = '\0';
    if (stash[i] == '\n')
        i++;// car substr prend la len et non l index 
    result = ft_substr(stash, i, ft_strlen(stash));// je recupere stash jusqu a \n 
    free(stash);
    return (result);

}

char *get_next_line(int fd)
{
    char *line;
    static char *str[1024]; // Variable statique pour conserver les données entre les appels

    if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
        return (NULL); // Vérification de la validité du descripteur de fichier et de la taille du buffer
    str[fd] = read_line(str[fd], fd);
    line = extract_line(str[fd]);
    str[fd] = clean_line(str[fd]);
    return (line);
}



// int main(void)
// {
//     int fd;
//     char buffer[200];
//     int size;
//     int byte_read;
//     size =12;
//     fd = open("filehuhuhkh.txt", O_RDONLY);
//     byte_read = read (fd, buffer, size);
//     printf("fd value : %d\n", fd);
//     if (byte_read < 0)
//     {
//         printf("byte _read value : %d\n", byte_read);
//         return 1;
//     }
//     buffer[byte_read] = '\0';
//     printf("%s\n", buffer);
//     return (0);
// }
