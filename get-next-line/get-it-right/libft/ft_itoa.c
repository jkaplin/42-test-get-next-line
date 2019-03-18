/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:44:13 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/04 20:24:55 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		i;

	size = ft_idigits(n);
	if (n < 0)
		size++;
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	i = size - 1;
	if (n == 0)
	{
		str[i] = '0';
		return (str);
	}
	while (n != 0)
	{
		str[i] = '0' + (int)ft_abs(n % 10);
		i--;
		n /= 10;
	}
	if (i == 0)
		str[i] = '-';
	return (str);
}
