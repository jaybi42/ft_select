/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/12 17:24:02 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
** TODO: Suppr stdio
*/

# include <stdio.h> //

# include "libft.h"
# include <termios.h>
# include <term.h>
# include <curses.h>

# define TERM		struct termios

typedef struct		s_elem
{
	t_ftl_node		node;
	char			*name;
	bool			selected;
}					t_elem;

typedef struct	s_error
{
	bool		cmd;
	char		*str;
	bool		arg;
}				t_error;

/*
**Name: Do select
**File: ft_select.c
**Desc: Parse ft_select
*/

int					ft_select(char **av, int ac);

/*
**Name: Terminal configuration
**File: c_term.c
**Desc: configure the terminal
*/

int					init_term(TERM *termios, TERM *termios_dfl);
int					reset_term(TERM *termios_dfl);

/*
**Name: List
**File: mod_list.c
**Desc: Parse list
*/

void				make_list(t_ftl_root *root, char **av, int ac);
//void				free_list();

/*
**Name: Error
**File: print_error.c
**Desc: Parce error
*/

int					print_error(char *cmd, int error);

#endif
