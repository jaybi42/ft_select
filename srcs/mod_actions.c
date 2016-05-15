/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nod_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:52:22 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/15 14:58:03 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			del_action(t_ftl_root *root, t_ftl_node *pos)
{
	t_ftl_node	node;

	node = pos->next;
	ftl_erase_pos(root, pos, NULL);
	pos = node;
	if (pos == root)
		pos = pos->next;
	pos->cursor = 1;
}

void		sel_action(t_ftl_root *root, t_ftl_node *pos)
{
	(void)root;
	pos->selected &= 1;
}
