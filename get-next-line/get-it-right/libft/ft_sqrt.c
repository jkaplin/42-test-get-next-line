/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:37:00 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/03 18:10:17 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define DIFF 0.1

double	ft_sqrt(double num)
{
	double	sqrt;
	double	sqrt_min;
	double	sqrt_max;

	sqrt_min = 0;
	sqrt_max = num / 2;
	sqrt = ft_average(sqrt_min, sqrt_max);
	while (ft_abs(sqrt * sqrt - num) > DIFF)
	{
		if (sqrt * sqrt > num)
			sqrt_max = sqrt;
		else
			sqrt_min = sqrt;
		sqrt = ft_average(sqrt_min, sqrt_max);
	}
	return (sqrt);
}
