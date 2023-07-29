#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define CHECK(X) \
		({\
			int __val = (X);\
			(\
			__val == -1 ? ({\
			printf("ERROR("__FILE__":%d) -- %s \n", __LINE__, strerror(errno));\
			exit(-1);-1;\
			}) : __val);\
		})
// the macro functions are forbidden 
int	main(int argc, char **argv)
{
	int		fd;
	int		readed;
	char	c;

	if (argc != 2)
	{
		printf("usage : %s <filename>\n", argv[0]);
		exit(-1);
	}
	CHECK(fd = open(argv[1], O_RDONLY));
	if (fd == -1)
	{
		printf("error = %d\n",errno);
		printf("the error's content is : %s\n", strerror(errno));
		exit(-1);
	}
	do
	{
		readed = read(fd, &c, 1);
		putc(c,stdout);
	}
	while (readed > 0);
	if (readed == -1)
	{
		printf("error = %d\n",errno);
		printf("the error's content is : %s\n", strerror(errno));
		exit(-1);
	}

	return (0);
}
