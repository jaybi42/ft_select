/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:20:51 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/13 17:00:47 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

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

static int		do_select()
{
	char		buf[5];

	ft_bzero(&buf, 5);
	while (1)
	{
		if (read(0, buf, 5) == -1)
			return (1);
		if (buf[0] == 27 && buf[1] == 0)
			return (0);
		if (actions(buf) == 1)
			return (1);
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
//	print_select(&root);
	int	ret;
	ret = do_select();
	reset_term(&termios_dfl);
	ft_putnbr(ret);
	return(0);
}
