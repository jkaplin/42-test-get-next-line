/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:24:59 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/03 15:56:30 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	*ptr_s;

	ptr = NULL;
	ptr_s = (char *)s;
	i = 0;
	while (ptr_s[i])
	{
		if (ptr_s[i] == (char)c)
			ptr = &ptr_s[i];
		i++;
	}
	if (c == '\0')
		ptr = &ptr_s[i];
	return (ptr);
}
