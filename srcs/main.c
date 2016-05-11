/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:33:47 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/11 18:07:43 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		how_to_use(void)
{
	ft_putendl("Put something NOOB !");
	return ;
}

int				main(int ac, char **av)
{
	if (ac > 1)
		ft_select(av, ac);
	else
		how_to_use();
	return (0);
}
