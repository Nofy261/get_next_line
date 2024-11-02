#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 10



void	*ft_calloc(unsigned int count, unsigned int size)//pas le mien
{
	void			*pointer;
	unsigned char	*p;
	unsigned int	n;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	p = pointer;
	n = size * count;
	while (n--)
		*p++ = '\0';
	return (pointer);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;
    //Verification s1 et s2 necessaire??
	k = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
		result[k++] = s1[i++];
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

char *get_first_line(char *stash, int fd)//lire la premiere ligne, on s arrete a \n
{
    int bytes_read; //nbre de caractere lu
    char    *buffer = NULL; // stocke temporairement les caracteres lues
    char    *line;// recupere la ligne
    if (stash == NULL) //s'il n'y a rien dans stash
        stash = ft_strdup(""); // ou ft_calloc
    bytes_read = 1; // 1 car sinon il ne va pas rentrer dans la boucle juste apres
    while (bytes_read > 0)// si le nombre de caractere lu est positif je fais une nouvelle lecture
    {
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
            return (NULL);
        bytes_read = read (fd, buffer, BUFFER_SIZE);// je lis et j'envoie dans buffer les caracteres lues
        if (bytes_read == -1)
            return (NULL);
        buffer[bytes_read] = '\0';//ou 0  j'enleve les caracteres lues afin de pouvoir accueillir les caracteres a lire suivant
        stash = ft_strjoin(stash, buffer);// je rajoute les caracteres lues par buffer dans stash 
        line = ft_strdup(stash);
        free (stash);
        if (ft_strchr(line, '\n'))
            break ;
    }
    free (buffer);// je free buffer a chaque fois 
    buffer = NULL;
    return (line);// est ce que c'est absolument la statique qui doit etre retournee ici?
}

char    *extract_line(char *stash)// je vais extraire la ligne qui m interesse
{
    int i;
    char *result;

    i = 0;
    if (!stash)
        return (NULL);
    while (stash[i] && stash[i] != '\n')//je compte le nombre de caracteres de stash 
        i++;
    result = ft_calloc(i + 2, sizeof(char));//i = taille de stash , +2 = \n et \0;// calloc a adapter
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        result[i] = stash[i];
        i++;
    }
    if (stash[i] && stash[i] == '\n')//je suis sur \n et non a la fin \0, ce qui veut dire qu il y a un autre mot a lire apres 
    {
        result[i] == '\n';//je rajoute \n a la chaine copiee
        i++;// je place i au debut du nouveau mot (Ex: Bonjour\nToi je prends Bonjour\n et je mets i sur T de Toi)
    }
    return (result);
}










char *get_next_line(int fd)
{
    char *line;
    static char *left_str; // Variable statique pour conserver les données entre les appels

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0); // Vérification de la validité du descripteur de fichier et de la taille du buffer

    left_str = ft_read_to_left_str(fd, left_str); // Lire et stocker le contenu dans left_str
    if (!left_str)
        return (NULL); // Gérer les erreurs de lecture

    line = ft_get_line(left_str); // Extraire la ligne complète de left_str
    left_str = ft_new_left_str(left_str); // Mettre à jour left_str pour la prochaine lecture
    return (line); // Retourner la ligne extraite
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
