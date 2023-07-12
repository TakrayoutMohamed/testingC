/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:52:27 by mohtakra          #+#    #+#             */
/*   Updated: 2023/07/10 18:33:35 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTREE_H
#define LIBTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_tree
{
	void *data;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

t_tree	*new_node(void *content);
void	add_right(t_tree **tree, t_tree *node);
void	add_left(t_tree **tree, t_tree *node);
void	delete_left(t_tree *tree, void (*del)(void *));
void	delete_right(t_tree *tree, void (*del)(void *));
void	delete_tree(t_tree **tree);
void    print_tree(t_tree *tree);

#endif
