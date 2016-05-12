/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:20:51 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/12 17:24:05 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		do_select(t_ftl_root *root)
{
	t_elem		*elem;

	elem = (t_elem *)root->next;
	while (elem != (t_elem *)root)
	{
		ft_putendl(elem->name);
		elem = (t_elem *)elem->node.next;
	}
}

int				ft_select(char **av, int ac)
{
	t_ftl_root	root;
	TERM		termios;
	TERM		termios_dfl;

	ftl_init(&root, sizeof(t_elem));
	make_list(&root, av, ac);
	if (init_term(&termios, &termios_dfl) == 1)
		return (1);
	do_select(&root);
	reset_term(&termios_dfl);
	return(0);
}
