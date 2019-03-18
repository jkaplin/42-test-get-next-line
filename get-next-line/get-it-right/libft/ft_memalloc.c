/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:45:59 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/04 20:26:49 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh_memory;

	fresh_memory = malloc(size);
	if (fresh_memory == NULL)
		return (NULL);
	fresh_memory = ft_memset(fresh_memory, 0, size);
	return (fresh_memory);
}
