#include <unistd.h>
#include <libc.h>
int main()
{
	char *c="alvares hello h";
	write(0,c,15);
	read(0,c,12);
	write(0,c,15);
	return (0);
}
