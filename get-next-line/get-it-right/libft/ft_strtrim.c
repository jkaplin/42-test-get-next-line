/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:05:16 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 08:32:34 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		start;
	int		end;

	start = 0;
	while (ft_isspace(s[start]))
		start++;
	end = ft_strlasti(s);
	while (end > start && ft_isspace(s[end]))
		end--;
	trimmed = ft_strnew(end - start + 1);
	if (trimmed == NULL)
		return (NULL);
	trimmed = ft_strncpy(trimmed, &s[start], end - start + 1);
	return (trimmed);
}
