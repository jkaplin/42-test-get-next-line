/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:55:07 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/04 10:22:55 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = ft_strnew(len);
	if (sub == NULL)
		return (NULL);
	sub = ft_strncpy(sub, &s[start], len);
	return (sub);
}
