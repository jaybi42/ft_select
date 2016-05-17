/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:50:04 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/17 14:50:13 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static int			do_termcap(char *key)
{
	char		*ret;

	if ((ret = tgetstr(key, NULL)) == NULL)
		return (print_error("ft_select", 4));
	tputs(ret, 0, int_putchar);
	return (0);
}

static int			error_size(void)
{
	do_termcap("cl");
	ft_putstr_fd("ft_select : TOO SMALL windows size.", 2);
	return (1);
}


static int			print_selected(char *name, bool cursor)
{
	if (cursor == 1)
	{
		ft_putstr_fd(H_RED, 2);
		do_termcap("us");
	}
	else
		ft_putstr_fd(H_BLUE, 2);
	do_termcap("so");
	ft_putendl_fd(name, 2);
	ft_putstr_fd(END, 2);
	do_termcap("se");
	if (cursor == 1)
		do_termcap("ue");
	ft_putstr_fd(END, 2);
	return (0);
}

static int			print_normal(char *name, bool cursor, int pos)
{
	if (cursor == 1)
	{
		ft_putstr_fd(H_RED, 2);
		do_termcap("us");
		ft_putstr_fd(name, 2);
		ft_putnbr_fd(pos, 2);
		ft_putchar_fd(pos, 2);
		do_termcap("ue");
		ft_putstr_fd(END, 2);
	}
	else
		ft_putendl_fd(name, 2);
	return (0);
}

int					print_select(t_ftl_root *root)
{
	t_ftl_node		*node;

	do_termcap("cl");
	node = (t_ftl_node *)root->next;
	while (node != (t_ftl_node *)root)
	{
		if (padding_control(root, node) == 1)
			return (error_size());
		if (((t_elem *)node)->selected == 1)
			print_selected(((t_elem *)node)->name, ((t_elem *)node)->cursor);
		else
			print_normal(((t_elem *)node)->name, ((t_elem *)node)->cursor, ((t_elem *)node)->pos);
		node = node->next;
	}
	return (0);
}
