/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:58:15 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/05 16:09:40 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
}
