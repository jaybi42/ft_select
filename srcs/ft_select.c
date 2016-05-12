/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:20:51 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/12 19:23:39 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static t_actions const	g_actions[5] = {
	{"", "\27\0\0\0", "ESC"},
	{"", "\27\91\65\0", "UP"},
	{"", "\27\91\66\0", "DOWN"},
	{"", "\27\91\67\0", "RIGHT"},
	{"", "\27\91\68\0", "LEFT"},
};

static void		print_select(t_ftl_root *root)
{
	t_elem		*elem;

	elem = (t_elem *)root->next;
	while (elem != (t_elem *)root)
	{
		ft_putendl(elem->name);
		elem = (t_elem *)elem->node.next;
	}
}

static void		do_select()
{
	char		buf[5];

	ft_bzero(&buf, 5);
	while (1)
	{
		if (read(0, buf, 5) == -1)
			return ;
		buf[4] = '\0';
		ft_putendl(buf);
		if (buf[0] == 27)
			return ;
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
	print_select(&root);
	do_select();
	reset_term(&termios_dfl);
	return(0);
}
