/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:59:02 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/18 13:23:06 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

static t_sig	g_sig = {NULL};

static void		is_sig(int signum)
{
	if (signum == SIGWINCH)
		print_select(g_sig.root);
	else if (signum == SIGINT)
	{
		do_termcap("cl");
		reset_term();
		exit(0);
	}
	else if (signum == SIGCONT)
	{
		init_term();
		print_select(g_sig.root);
		ft_putendl_fd("test", 2);
		ft_putendl_fd("test", 1);
	}
}

void			catch_sig(t_ftl_root *root)
{
	g_sig.root = root;
	signal(SIGWINCH, is_sig);
	signal(SIGINT, is_sig);
	signal(SIGCONT, is_sig);
	signal(SIGSTOP, SIG_IGN);
}
