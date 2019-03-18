/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:30:08 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/03 16:01:03 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		k = i;
		ptr = &((char *)haystack)[k];
		while (needle[j] == haystack[k])
		{
			if (needle[j + 1] == '\0')
				return (ptr);
			j++;
			k++;
		}
		i++;
	}
	ptr = NULL;
	if (needle[0] == '\0')
		ptr = (char *)haystack;
	return (ptr);
}
