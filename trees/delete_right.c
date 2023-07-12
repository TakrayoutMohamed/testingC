/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:30:40 by mohtakra          #+#    #+#             */
/*   Updated: 2023/07/09 18:36:39 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libtree.h"

/*delete the right leaf if the it has no child*/
void	delete_right(t_tree *tree, void (*del)(void *))
{
	t_tree	*tmp;

	tmp = tree;
	while (tmp->right != NULL)
	{
		tmp = tmp->right;
	}
	if (tmp->right == NULL && tmp->left == NULL)
	{
		del(tmp);
		free(tmp);
	}
}
