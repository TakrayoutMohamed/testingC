/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:13:49 by mohtakra          #+#    #+#             */
/*   Updated: 2023/07/10 18:25:55 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libtree.h"

void	add_left(t_tree **tree, t_tree *node)
{
	t_tree	*tmp;

	tmp = *tree;
	if (tmp->left != NULL)
	{
		printf("this address is already in use in add_left()\n ");
		return ;
	}
	tmp->left = node;
}
