#include "./libtree.h"

t_tree *new_node(void *content)
{
	t_tree *tree;

	tree = malloc (sizeof(t_tree));
	if (!tree)
		return (NULL);
	else
	{
		tree->data = content;
		tree->left = NULL;
		tree->right = NULL;
	}
	return (tree);
}
