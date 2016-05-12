/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_term.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:38:33 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/12 17:00:42 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>

/*
** TERMIOS STRUCT
** {
** tcflag_t		c_iflag
** tcflag_t		c_oflag
** tcflag_t		c_cflag
** tcflag_t		c_lflag
** cc_t			c_cc[NCCS]
** speed_t		c_ispeed
** speed_t		c_ospeed
** }
*/

int			reset_term(TERM *termios)
{
	termios->c_lflag &= ~(ICANON);
	termios->c_lflag &= ~(ECHO);
	termios->c_cc[VMIN] = 1;
	termios->c_cc[TIME] = 0;
	return (0);
}

int			init_term(TERM *termios)
{
	char	*term;

	term = getenv("TERM");
	if (term == NULL)
		return (print_error("ft_select", 0));
	if (tgetent(NULL, term) != 1)
		return (print_error("ft_select", 1));
	termios->c_lflag &= ~(ICANON);
	termios->c_lflag &= ~(ECHO);
	termios->c_cc[VMIN] = 1;
	termios->c_cc[TIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}
