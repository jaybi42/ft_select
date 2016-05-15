/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:50:04 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/15 18:23:19 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static int		do_termcap(char *key)
{
	char		*ret;

	if ((ret = tgetstr(key, NULL)) == NULL)
		return (print_error("ft_select", 4));
	tputs(ret, 0, int_putchar);
	return (0);
}

static int		print_selected(char *name, bool cursor)
{
	if (cursor == 1)
		do_termcap("us");
	do_termcap("so");
	ft_putendl_fd(name, 2);
	do_termcap("se");
	if (cursor == 1)
		do_termcap("ue");
	return (0);
}

static int		print_normal(char *name, bool cursor)
{
	if (cursor == 1)
	{
		do_termcap("us");
		ft_putendl_fd(name, 2);
		do_termcap("ue");
	}
	else
		ft_putendl_fd(name, 2);
	return (0);
}

void			print_select(t_ftl_root *root)
{
	t_ftl_node	*node;

	do_termcap("cl");
	node = (t_ftl_node *)root->next;
	while (node != (t_ftl_node *)root)
	{
		if (((t_elem *)node)->selected == 1)
			print_selected(((t_elem *)node)->name, ((t_elem *)node)->cursor);
		else
			print_normal(((t_elem *)node)->name, ((t_elem *)node)->cursor);
		node = node->next;
	}
}
