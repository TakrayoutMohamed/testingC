#include <fcntl.h>
#include <unistd.h>

void ft_putstr_fd(char *str, int fd)
{
	int i;
	i = 0;

	while(str[i] != '\0'){
		write(fd, &str[i], 1);
		i++; 
}
}

int main(){
	int fd = open("file00.txt",O_CREAT | O_RDWR | O_APPEND ,777);
	ft_putstr_fd("hello all ", fd);
}