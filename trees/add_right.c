/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:17:56 by mohtakra          #+#    #+#             */
/*   Updated: 2023/07/10 18:26:30 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libtree.h"

void    add_right(t_tree **tree, t_tree *node)
{
    t_tree *tmp;

    tmp = *tree;
    if (tmp->right != NULL)
    {
        printf("this address is already in use in add_right()\n ");
		return ;
    }
    tmp->right = node;
}
