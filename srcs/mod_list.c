/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:54:18 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/13 17:35:43 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		make_list(t_ftl_root *root, char **av, int ac)
{
	t_elem	elem;

	while (--ac > 0)
	{
		elem.name = av[ac];
		elem.selected = 0;
		elem.cursor = 0;
		ftl_push_front(root, (FTL_NODE *)(&elem));
	}
}
