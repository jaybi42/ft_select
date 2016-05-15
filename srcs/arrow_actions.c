/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:43:55 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/15 17:09:48 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		up_action(t_ftl_root *root, t_ftl_node **pos)
{
	((t_elem *)*pos)->cursor = 0;
	*pos = (*pos)->prev;
	if (*pos == (t_ftl_node *)root)
		*pos = (*pos)->prev;
	((t_elem *)*pos)->cursor = 1;
}

void		down_action(t_ftl_root *root, t_ftl_node **pos)
{
	((t_elem *)*pos)->cursor = 0;
	*pos = (*pos)->next;
	if (*pos == (t_ftl_node *)root)
		*pos = (*pos)->next;
	((t_elem *)*pos)->cursor = 1;
}

void		right_action(t_ftl_root *root, t_ftl_node **pos)
{
	(void)root;
	(void)pos;
	return ;
}

void		left_action(t_ftl_root *root, t_ftl_node **pos)
{
	(void)root;
	(void)pos;
	return ;
}
