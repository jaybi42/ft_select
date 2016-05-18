/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 13:16:10 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/18 13:18:30 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

int				do_termcap(char *key)
{
	char		*ret;

	if ((ret = tgetstr(key, NULL)) == NULL)
		return (print_error("ft_select", 4));
	tputs(ret, 0, int_putchar);
	return (0);
}

