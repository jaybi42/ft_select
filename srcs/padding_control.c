/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 18:11:42 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/17 15:06:35 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>
#include <unistd.h>

static int          move_termcap(char *key, int col, int row)
{
    char			*ret;

    if ((ret = tgetstr(key, NULL)) == NULL)
        return (print_error("ft_select", 4));
    ret = tgoto(ret, col, row);
    tputs(ret, 0, int_putchar);
    return (0);
}

static int			get_maxlen(t_ftl_root *root)
{
	t_ftl_node		*node;
	int				max_len;

	max_len = 0;
	node = root->next;
	while (node != (t_ftl_node *)root)
	{
		if (((t_elem *)node)->name_len > max_len)
			max_len = ((t_elem *)node)->name_len;
		node = node->next;
	}
	return (max_len);
}

int					padding_control(t_ftl_root *root, t_ftl_node *node)
{
	struct winsize	win;
	int				col;
	int				row;
	int				max_len;

	ioctl(0, TIOCGWINSZ, &win);
	max_len = get_maxlen(root) + 5;
	if (((win.ws_col / max_len) * win.ws_row) < (int)root->size)
		return (1);
	col = ((t_elem *)node)->pos / (win.ws_row - 1) * max_len;
	row = ((t_elem *)node)->pos % (win.ws_row - 1);
	move_termcap("cm", col, row);
	return (0);
}
