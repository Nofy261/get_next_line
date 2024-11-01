#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 10

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[k] = s1[i];
		i++;
		k++;
	}
	j = 0;
	while (s2[j])
		result[k++] = s2[j++];
	result[k] = '\0';
    //free(s1);
    //s1 = NULL;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char *line(char *stash, int fd)//recupere toute la ligne lue cad de la taille de buffer_size
{
    //int i;
    int bytes_read;
    char    *buffer = NULL;

    //i = 0;
    if (stash != NULL)
    {
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
            return (NULL);
        bytes_read = read (fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        if (bytes_read > 0)
            stash = ft_strjoin(stash, buffer);
        free (buffer);
        buffer = NULL;
    }
    else
        stash = ft_strdup("");
    while (strchr(stash, "\n") == NULL)
    {
        

    }
     

    


    //return (stash)
}




char *get_next_line(int fd)
{
    static char *stash = NULL;
    
    if (!fd  || BUFFER_SIZE =< 0)
        return (NULL);
    // stash = line




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