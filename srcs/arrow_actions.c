/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:43:55 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/15 15:05:14 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		up_list(t_ftl_root *root, t_ftl_node *pos)
{
	pos->cursor = 0
	pos = pos->prev;
	if (pos == root)
		pos = pos->prev;
	pos->cursor = 1
}

void		down_list(t_ftl_root *root, t_ftl_node *pos)
{
	pos->cursor = 0
	pos = pos->next;
	if (pos == root)
		pos = pos->next;
	pos->cursor = 1
}

void		right_list(t_ftl_root *root, t_ftl_node *pos)
{
	return ;
}

void		left_list(t_ftl_root *root, t_ftl_node *pos)
{
	return ;
}
