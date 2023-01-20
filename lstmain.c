#include "./../RepoLibft/libft.h"

void	ft_lstaffiche(t_list *lst)
{
	if (!lst)
		printf("\nlst is emply\n");
	else
	{
		while (lst)
		{
			printf("%d -> ",*(int *)lst->content);
			lst = lst->next;
		}
		printf("\n");
	}
}
void	f(void *content)
{
	printf("%d\n",(*(int *)content) + 1);
}

void *g(void *content)
{
	*(int*)content = *(int*)content * 2;
	return (content);
}

void del(void *content)
{
	content = NULL;
}

int	main(void)
{
	t_list	*lst = NULL;
	t_list	*temp;
	t_list	*temp2;
	t_list	*resultimap;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 5;
	k = 6;
	ft_lstaffiche(lst);

	printf("\nthe lstnew function------------\n");
	temp = ft_lstnew(&i);

	printf("\nthe lstadd_front function------------\n");
	ft_lstadd_front(&lst,temp);
	temp = ft_lstnew(&j);
	ft_lstadd_front(&lst,temp);
	i++;

	printf("\nthe lstadd_back function------------\n");
	temp = ft_lstnew(&k);
	ft_lstadd_back(&lst,temp);
	i++;
	
	ft_lstaffiche(lst);
	printf("\nthe lstsize_back function------------\n");
	printf("\nsize of lst lst : %d\n",ft_lstsize(lst));

	printf("\nthe lstlast function------------\n");
	printf("\nthe last of the lst is  : %d\n",*(int*)(ft_lstlast(lst))->content);
	
	printf("\nthe lstiteri function------------\n");
	ft_lstiter(lst,f);

	printf("\nthe lstmap function------------\n");
	resultimap = ft_lstmap(lst,g,del);
	ft_lstaffiche(resultimap);

	printf("\nthe lstdelone function------------\n");
	temp2 = lst->next;
	ft_lstdelone(lst, del);
	lst = temp2;
	printf("\nsize of lst lst : %d\n",ft_lstsize(lst));
	ft_lstaffiche(lst);

	printf("\nthe lstclear function------------\n");
	ft_lstclear(&lst, del);
	printf("\nsize of lst lst : %d\n",ft_lstsize(lst));
	ft_lstaffiche(lst);
	temp = NULL;
	printf("size of lst temp is : %d\n",ft_lstsize(temp));
	return (0);
}

