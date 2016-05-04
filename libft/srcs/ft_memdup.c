/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:54:03 by jguthert          #+#    #+#             */
/*   Updated: 2016/05/04 16:58:00 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memdup(void const *data, size_t size)
{
	void		*new;

	new = malloc(size);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, p, size);
	return (new);
}
