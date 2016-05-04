/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_destruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 18:00:40 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/04 18:36:55 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ftl_release(t_ftl_root *l, void (*delalloc)())
{

}

void			ftl_pop_back(t_ftl_root *l, void (*delalloc)())
{
	t_ftl_node	temp;

	temp = l->prev;
	free(temp);
}

void			ftl_pop_front(t_ftl_root *l, void (*delalloc)())
{
	t_ftl_node	temp;

	temp = l->next;
	free(temp);
}

void			ftl_erase_pos(t_ftl_root *l, t_ftl_node *pos, void (*delalloc)())
{
	free(temp);
}
