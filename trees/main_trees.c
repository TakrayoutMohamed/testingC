#include "./libtree.h"

int main(void)
{
    t_tree *tr1 = new_node((int *)1);
    t_tree *tr2 = new_node((int *)2);
    t_tree *tr3 = new_node((int *)3);
    t_tree *tr4 = new_node((int *)4);
    t_tree *tr5 = new_node((int *)5);

    // tr1->left = tr3;
    add_left(&tr1,tr3);
    // tr1->right = tr2;
    add_right(&tr1,tr2);
    // tr2->left = tr4;
    add_left(&tr2,tr4);
    // tr2->right = tr5;
    add_right(&tr2,tr5);
    print_tree(tr1);
    return (0);
}