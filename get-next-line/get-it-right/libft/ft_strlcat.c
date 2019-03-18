/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:46:07 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/04 20:00:41 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;
	int		real_dstsize;

	i = ft_strlen(dst);
	real_dstsize = i;
	j = 0;
	while (src[j] && i < (int)dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < (int)dstsize)
		dst[i] = '\0';
	return (ft_min(real_dstsize, dstsize) + ft_strlen(src));
}
