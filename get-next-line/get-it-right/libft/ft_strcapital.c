/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapital.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:05:36 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/03 18:38:13 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapital(const char *str)
{
	char	*strcapital;
	int		i;

	strcapital = ft_strnew(ft_strlen(str));
	if (strcapital == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			strcapital[i] = ft_toupper(str[i]);
			i++;
			break ;
		}
		strcapital[i] = str[i];
		i++;
	}
	while (str[i])
	{
		strcapital[i] = ft_tolower(str[i]);
		i++;
	}
	strcapital[i] = '\0';
	return (strcapital);
}
