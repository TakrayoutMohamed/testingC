#include "./../RepoLibft/libft.h"
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
}

int main()
{
	int fd1, sz;
	int ftoreadfrom = open("alvarestext.txt",O_RDONLY);
	char c;
	char *str = "nice exezzaample";
	//fd1 = open("alvarestext1.txt",O_WRONLY | O_CREAT,0600);
	fd1 = creat("alvarestxt.txt",0666);
	ft_putstr_fd(str, fd1);
	printf("\n-----------------------------\n");
	while (read(ftoreadfrom, &c, sizeof(c)))
	{
		printf("%c",c);
	}
	
	close(fd1);
	close(ftoreadfrom);
}
