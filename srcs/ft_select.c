/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:20:51 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/17 15:12:17 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static void		give_list(t_ftl_root *root)
{
	t_ftl_node	*node;

	node = root->next;
	while (node != (t_ftl_node *)root)
	{
		ft_putstr_fd(((t_elem *)node)->name, 1);
		ft_putchar_fd(' ', 1);
		node = node->next;
	}
}

static int		do_select(t_ftl_root *root)
{
	char		buf[5];
	t_ftl_node	*pos;

	pos = root->next;
	while (1)
	{
		if (print_select(root) == 1)
			continue ;
		ft_bzero(&buf, 5);
		if (read(0, buf, 5) == -1)
			return (1);
		if (buf[0] == 27 && buf[1] == 0)
			return (0);
		if (buf[0] == 10 && buf[1] == 0)
			return (2);
		if (actions(buf, root, &pos) == 1)
			return (1);
		if (pos == (t_ftl_node *)root)
			return (0);
	}
}

int				ft_select(char **av, int ac)
{
	t_ftl_root	root;
	TERM		termios;
	TERM		termios_dfl;
	int			ret;

	ftl_init(&root, sizeof(t_elem));
	if (init_list(&root, av, ac) == 1)
		return (print_error("ft_select", 6));
	if (init_term(&termios, &termios_dfl) == 1)
		return (1);
	catch_sig(&root, &termios, &termios_dfl);
	ret = do_select(&root);
	reset_term(&termios_dfl);
	if (ret == 2)
		give_list(&root);
	return(0);
}
