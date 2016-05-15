/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:20:51 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/15 17:58:31 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static void		print_list(t_ftl_root *root, t_ftl_node *pos)
{
	t_ftl_node	*node;

	node = root->next;
	while (node != (t_ftl_node *)root)
	{
		ft_putendl_fd(((t_elem *)node)->name, 2);
		ft_putnbr_fd(((t_elem *)node)->selected, 2);
		ft_putchar_fd('\n', 2);
		ft_putnbr_fd(((t_elem *)node)->cursor, 2);
		ft_putchar_fd('\n', 2);
//		ft_putstr_fd("-----------------", 2);
		node = node->next;
	}
	ft_putendl_fd(((t_elem *)pos)->name, 2);
}

static int		do_select(t_ftl_root *root)
{
	char		buf[5];
	t_ftl_node	*pos;

	pos = root->next;
	while (1)
	{
		ft_bzero(&buf, 5);
		if (read(0, buf, 5) == -1)
			return (1);
		if (buf[0] == 27 && buf[1] == 0)
			return (0);
		if (buf[0] == 10 && buf[1] == 0)
			return (0);
		if (actions(buf, root, &pos) == 1)
			return (1);
		if (pos == (t_ftl_node *)root)
			return (0);
		print_select(root);
//		print_list(root, pos);
	}
}

int				ft_select(char **av, int ac)
{
	t_ftl_root	root;
	TERM		termios;
	TERM		termios_dfl;

	ftl_init(&root, sizeof(t_elem));
	init_list(&root, av, ac);
	if (init_term(&termios, &termios_dfl) == 1)
		return (1);
	do_select(&root);
	reset_term(&termios_dfl);
	return(0);
}
