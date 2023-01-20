#include "./../RepoLibft/libft.h"


void    del(void *ptr)
{
    free(ptr);
}

int main()
{
    t_list *list;
    char *name = ft_strdup("mohamed");
    list = ft_lstnew(name);
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("hassan")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("anas")));
    t_list *tmp = list;
    for (int i=0;i<3;i++)
    {
        printf("%s\n",(char *)tmp->content);
        tmp = tmp->next;
    }
    t_list *tmp2;
    tmp2 = list->next;
    tmp = tmp2->next;
    ft_lstdelone(tmp2, del);
    list = tmp;
    // ft_lstdelone(tmp2, del);
    // printf("%d\n",ft_lstsize(list));
    // int size = ft_lstsize(list);
    for (int i=0;i < 1;i++)
    {
        printf("%s\n",(char *)list->content);
        list = list->next;
        // printf("%d\n",i);
    }
}