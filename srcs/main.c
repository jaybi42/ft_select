/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:33:47 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/04 12:20:37 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				main(int ac, char **av)
{
	if (ac >= 1)
		ft_select(av);
	else
		ft_putendl("ft_select: Wrong number of arguments.");
	return (0);
}
