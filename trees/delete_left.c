/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:17:49 by mohtakra          #+#    #+#             */
/*   Updated: 2023/07/09 20:48:39 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libtree.h"

/*delete the left leaf if the it has no child*/
void	delete_left(t_tree *tree, void (*del)(void *))
{
	t_tree	*tmp;

	tmp = tree;
	while (tmp->left != NULL && tmp->right != NULL)
	{
		tmp = tmp->left;
	}
	if (tmp->left == NULL && tmp->right == NULL)
	{
		del(tmp);
		free(tmp);
	}
}
