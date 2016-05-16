/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:38:33 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/16 14:13:00 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>

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

int			reset_term(TERM *termios_dfl)
{
	char	*ret;

	if ((ret = tgetstr("ve", NULL)) == NULL)
		return (print_error("ft_select", 4));
	tputs(ret, 0, int_putchar);
	if (tcsetattr(0, TCSADRAIN, termios_dfl) == -1)
		return (print_error("ft_select", 2));
	if ((ret = tgetstr("cl", NULL)) == NULL)
		return (print_error("ft_select", 4));
	tputs(ret, 0, int_putchar);
	return (0);
}

int			init_term(TERM *termios, TERM *termios_dfl)
{
	char	*term;
	char	*ret;

	term = getenv("TERM");
	if (term == NULL)
		return (print_error("ft_select", 0));
	if (tgetent(NULL, term) != 1)
		return (print_error("ft_select", 1));
	if (tcgetattr(0, termios_dfl) == -1)
		return (print_error("ft_select", 3));
	termios->c_lflag &= ~(ICANON);
	termios->c_lflag &= ~(ECHO);
	termios->c_cc[VMIN] = 1;
	termios->c_cc[VTIME] = 0;
	if ((ret = tgetstr("vi", NULL)) == NULL)
		return (print_error("ft_select", 4));
	tputs(ret, 0, int_putchar);
	if (tcsetattr(0, TCSADRAIN, termios) == -1)
		return (print_error("ft_select", 2));
	return (0);
}
