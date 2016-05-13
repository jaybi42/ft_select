/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:49:16 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/13 17:45:45 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static t_actions const	g_actions[4] = {
	{"cl", {27, 91, 65, 0}, "UP"},
	{"cl", {27, 91, 66, 0}, "DOWN"},
	{"cl", {27, 91, 67, 0}, "RIGHT"},
	{"cl", {27, 91, 68, 0}, "LEFT"},
	{"cl", {27, 91, 51, 0}, "BACKSPACE"},
	{"cl", {127, 0, 0, 0}, "DELETE"},
	{"cl", {32, 0, 0, 0}, "SPACEBAR"},
	{"cl", {27, 68, 0, 0}, "ENTER"},
};

static int		int_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

static int		cmp_buf(int *value, char *buf)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (buf[i] != value[i])
			return (1);
		i++;
	}
	return (0);
}

int				actions(char *buf)
{
	char		*ret;
	int			i;

	i = 0;
	while (i < 4)
	{
		if (cmp_buf((int *)g_actions[i].value, buf) == 0)
		{
			if ((ret = tgetstr("cl", NULL)) == NULL)
				return (print_error("ft_select", 4));
			tputs(ret, 0, int_putchar);
			if ((ret = tgetstr(g_actions[i].action, NULL)) == NULL)
				return (print_error("ft_select", 4));
			tputs(ret, 0, int_putchar);
			return (0);
		}
		i++;
	}
	return (0);
}
