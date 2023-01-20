#include "./../RepoLibft/libft.h"


void del(void *str)
{
    str = NULL;
    free(str);
}

int main ()
{

    t_list *head = NULL;

    t_list *mouad = ft_lstnew(ft_strdup("mouad"));
    t_list *moh = ft_lstnew(ft_strdup("mohamed"));
    t_list *jamal = ft_lstnew(ft_strdup("jamal"));
    t_list *anas = ft_lstnew(ft_strdup("anas"));

    ft_lstadd_back(&head, mouad);
    ft_lstadd_back(&head, moh);
    ft_lstadd_back(&head, jamal);
    ft_lstadd_back(&head, anas);


    t_list *temp = head;

    ft_lstdelone(head, del);
    temp = temp->next;
    ft_lstdelone(moh, del);
    printf("\nff\n");
    head = temp;
    printf("\nff\n");


    while (head != NULL)
    {
        if (head->content != NULL)
            printf("%s\n", head->content);
        head = head->next;
    }
    

    return (0);
}