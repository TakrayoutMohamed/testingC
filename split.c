#include "./../RepoLibft/libft.h"

int main()
{
    int i,j;
    i = 0;
    j = 0;
	char *str = "   hello my name is alvares   ";
	char **res = ft_split(str, ' ');
	printf("the string is : --%s--\n",str);
	while (res[i])
	{
        printf("%s\t",res[i]);
        i++;
	}
    i = 0;
    if (res[i])
    {
       printf("\nh1");
    }
    else 
       printf("\nh2");
    printf("\n size of matrix is : %zu \n",sizeof(res));
    ft_freematrix(res);
    printf("\n size of matrix is : %zu \n",sizeof(res));
    
    if (res[i])
    {
       printf("\nh1");
    }
    else 
       printf("\nh2");
    while (res[i])
	{
        printf("%s\t",res[i]);
        i++;
	}
	return 0;
}