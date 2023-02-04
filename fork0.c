#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	// static int i;
	int	idd = 1000;
	int a = 5;

	idd = fork();
	if (idd != 0)
	{
		printf("I'm in child a = %d\n" ,a);
		printf("\nmy id is : %d\n",getpid());
		// printf("\nmy parents id is : %d\n",getppid());
	}
	// idd = fork();
	// if (id == 0)
	// {
	// 	printf("hello from child\n");
	// }
	else{
		a = 6;
		int i = 0;
		printf("\nidd = %d a = %d\n", idd, a);
		printf("\nmy id is : %d\n",getpid());
		// printf("\nmy parents id is : %d\n",getppid());
		// wait(NULL);
		printf("alvares");
		// while(1)
		// {
		// 	printf("");
		// }
	}
	return (0);
}