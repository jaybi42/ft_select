/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:59:02 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/16 17:32:28 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

static t_sig	g_sig = {NULL, NULL, NULL};

static void		is_sig(int signum)
{
	if (signum == SIGWINCH)
		print_select(g_sig.root);
	else if (signum == SIGINT)
	{
		reset_term(g_sig.term);
		exit(0);
	}
	else if (signum == SIGCONT)
		init_term(g_sig.term, g_sig.term_dfl);
}

void			catch_sig(t_ftl_root *root, TERM *term, TERM *term_dfl)
{
	g_sig.root = root;
	g_sig.term = term;
	g_sig.term_dfl = term_dfl;
	signal(SIGWINCH, is_sig);
	signal(SIGINT, is_sig);
	signal(SIGCONT, is_sig);
	signal(SIGSTOP, SIG_IGN);
}
