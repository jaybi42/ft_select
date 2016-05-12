/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:20:51 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/12 17:02:04 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

static int		init_term(TERM *termios)
{
	char		*term;

	term = getenv("TERM");
	if (term == NULL)
		return (print_error("ft_select", 0));
	if (tgetent(NULL, term) != 1)
		return (print_error("ft_select", 1));
	return (0);
}

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

	ftl_init(&root, sizeof(t_elem));
	make_list(&root, av, ac);
	if (init_term(&termios) == 1)
		return (1);
	while (1)
	{
		do_select(&root);
//		if ()
		exit(0);
	}
//	reset_term(termios);
	return(0);
}
