/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/15 17:05:11 by jguthert         ###   ########.fr       */
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
	bool			cursor;
}					t_elem;

typedef void		(*modl_t) (t_ftl_root *root, t_ftl_node **pos);

typedef struct		s_actions
{
	modl_t			action;
	int				value[4];
	char			*key;
}					t_actions;

typedef struct		s_error
{
	bool			cmd;
	char			*str;
	bool			arg;
}					t_error;

/*
**Name: Do select
**File: ft_select.c
**Desc: Parse ft_select
*/

int					ft_select(char **av, int ac);

/*
**Name: actions
**File: arrow_actions.c mod_actions.c
**Desc: actions fonctions
*/

int					actions(char *buf, t_ftl_root *root, t_ftl_node **pos);
void				up_action(t_ftl_root *root, t_ftl_node **pos);
void				down_action(t_ftl_root *root, t_ftl_node **pos);
void				right_action(t_ftl_root *root, t_ftl_node **pos);
void				left_action(t_ftl_root *root, t_ftl_node **pos);
void				del_action(t_ftl_root *root, t_ftl_node **pos);
void				sel_action(t_ftl_root *root, t_ftl_node **pos);

/*
**Name: Terminal configuration
**File: c_term.c
**Desc: configure the terminal
*/

int					init_term(TERM *termios, TERM *termios_dfl);
int					reset_term(TERM *termios_dfl);

/*
**Name: Print
**File: print_term.c int_putchar.c
**Desc: Print ft_select
*/

void				print_select(t_ftl_root *root);
int					int_putchar(int c);

/*
**Name: List
**File: mod_list.c
**Desc: Parse list
*/

void				init_list(t_ftl_root *root, char **av, int ac);

/*
**Name: Error
**File: print_error.c
**Desc: Parce error
*/

int					print_error(char *cmd, int error);

#endif
