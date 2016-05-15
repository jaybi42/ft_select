/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:54:18 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/15 15:03:02 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		init_list(t_ftl_root *root, char **av, int ac)
{
	t_elem	elem;

	ft_bzero(elem, (sizeof(t_elem)));
	while (--ac > 1)
	{
		elem.name = av[ac];
		ftl_push_front(root, (FTL_NODE *)(&elem));
	}
	elem.name = av[ac];
	elem.cursor = 1;
	ftl_push_front(root, (FTL_NODE *)(&elem));
}
