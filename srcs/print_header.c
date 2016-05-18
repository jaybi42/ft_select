/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:02:12 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/18 16:15:24 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			p_h(char *str, int space, int color)
{
	ft_putstr_fd("\e[38;5;", 2);
	ft_putnbr_fd(color, 2);
	ft_putchar_fd('m', 2);
	while (space-- > 0)
		ft_putchar_fd(' ', 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
}

static void			header_min(int s)
{
	int		c;

	c = 240;
	p_h(" ______ _______ _____ ______ _      ______ _____ _______", s, c++);
	p_h("|  ____|__   __/ ____|  ____| |    |  ____/ ____|__   __|", s, c++);
	p_h("| |__     | | | (___ | |__  | |    | |__ | |       | |", s, c++);
	p_h("|  __|    | |  \\___ \\|  __| | |    |  __|| |       | |", s, c++);
	p_h("| |       | |  ____) | |____| |____| |___| |____   | |", s, c++);
	p_h("|_|       |_| |_____/|______|______|______\\_____|  |_|", s, c++);
	p_h("          ______", s, c++);
	p_h("         |______|", s, c);

}

static void			header_max(int s)
{
	int		c;

	c = 240;
	p_h(" ______ _______ _____ ______ _      ______ _____ _______", s, c++);
	p_h("|  ____|__   __/ ____|  ____| |    |  ____/ ____|__   __|\
     [Arrows]        Navigate in the list", s, c++);
	p_h("| |__     | | | (___ | |__  | |    | |__ | |       | |\
        [Enter]         Validate selection", s, c++);
	p_h("|  __|    | |  \\___ \\|  __| | |    |  __|| |       | |\
        [Space bar]     Select a file", s, c++);
	p_h("| |       | |  ____) | |____| |____| |___| |____   | |\
        [Delete]        Delete a file", s, c++);
	p_h("|_|       |_| |_____/|______|______|______\\_____|  |_|", s, c++);
	p_h("          ______                                      \
        [ESC]           Exit the program", s, c++);
	p_h("         |______|", s, c);
}

void				print_header(void)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	if (win.ws_col > 102)
		header_max((win.ws_col - 100) / 2);
	else if (win.ws_col > 59)
		header_min((win.ws_col - 57) / 2);
}
