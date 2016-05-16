/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/16 21:09:15 by jguthert         ###   ########.fr       */
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

# define H_RED		"\033[1;91m"
# define H_BLUE		"\033[1;94m"
# define END		"\033[0m"

typedef struct		s_sig
{
	t_ftl_root		*root;
	TERM			*term;
	TERM			*term_dfl;
}					t_sig;

typedef struct		s_elem
{
	t_ftl_node		node;
	char			*name;
	int				name_len;
	int				pos;
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
**File: print_term.c int_putchar.c padding_control,.c
**Desc: Print ft_select
*/

int					print_select(t_ftl_root *root);
int					int_putchar(int c);
int					padding_control(t_ftl_root *root, t_ftl_node *node);

/*
**Name: List
**File: mod_list.c
**Desc: Parse list
*/

int					init_list(t_ftl_root *root, char **av, int ac);

/*
**Name: Error
**File: print_error.c
**Desc: Parce error
*/

int					print_error(char *cmd, int error);

/*
**Name: Error
**File: print_error.c
**Desc: Parce error
*/

void				catch_sig(t_ftl_root *root, TERM *term, TERM *term_dfl);

#endif
