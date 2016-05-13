/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:50:04 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/13 17:57:50 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static int		int_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

static void		reset_select()
{
	if ((ret = tgetstr("cl", NULL)) == NULL)
		return (print_error("ft_select", 4));
	tputs(ret, 0, int_putchar);
}

static void		customize()

void			print_select(t_ftl_root *root)
{
	t_elem		*elem;

	reset_select();
	elem = (t_elem *)root->next;
	while (elem != (t_elem *)root)
	{
		ft_putendl(elem->name);
		elem = (t_elem *)elem->node.next;
	}
}
