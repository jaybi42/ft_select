/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:15:07 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/12 16:29:52 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_error const	g_print[2] = {
	{1, " : Env not found.", 0},
	{1, " : Wrong terminal information.", 0},
};

int	print_error(char *cmd, int error)
{
	if (g_print[error].cmd == 1)
		ft_putstr(cmd);
	ft_putstr(g_print[error].str);
	if (g_print[error].arg == 1)
		ft_putstr("");
	ft_putchar('\n');
	return (1);
}
