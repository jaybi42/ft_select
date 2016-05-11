/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:56:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/11 18:02:29 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
** TODO: Suppr stdio
*/

# include <stdio.h> //

# include "libft.h"

typedef struct		s_elem
{
	t_ftl_node		*list;
	char			*name;
	bool			selected;
}					t_elem;

/*
**Name: Do select
**File: ft_select.c
**Desc: Parse ft_select
*/

void				ft_select(char **av, int ac);

/*
**Name: List
**File: mod_list.c
**Desc: Parse list
*/

void				make_list(t_ftl_root *root, char **av, int ac);
//void				free_list();

#endif
