/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:50:04 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/15 16:13:20 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static int		reset_select(void)
{
	char		*ret;

	if ((ret = tgetstr("cl", NULL)) == NULL)
		return (print_error("ft_select", 4));
	tputs(ret, 0, int_putchar);
	return (0);
}

static void		print_selected(char *name, bool cursor)
{
	return ;
}

static void		print_normal(char *name, bool cursor)
{
	char		*ret;

	if (cursor == 1)
	{
		return ;
//		ft_putendl_fd(name, 2);
	}
	else
		return ;
//		ft_putendl_fd(name, 2);
}

void			print_select(t_ftl_root *root)
{
	t_ftl_node	*node;

	reset_select();
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
