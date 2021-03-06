/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:27:35 by josantos          #+#    #+#             */
/*   Updated: 2021/05/31 14:33:41 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			a;
	int			b;
	long long	c;

	a = 0;
	b = 1;
	c = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if ((str[a] == '-') || (str[a] == '+'))
	{
		if (str[a] == '-')
			b *= -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = (c * 10) + (str[a] - '0');
		a++;
		if (c > 2147483647)
			return (2147483647);
		if (c < -2147483648)
			return (-2147483648);
	}
	return (c * b);
}
