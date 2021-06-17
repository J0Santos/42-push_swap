/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:15:29 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 18:08:26 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printnum(int n)
{
	int	c;

	c = 0;
	if (n == 0)
	{
		c = 1;
		return (c);
	}
	if (n < 0)
		c++;
	while (n)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		b;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	b = printnum(n);
	p = (char *)malloc(sizeof(char) * (b + 1));
	if (p == 0)
		return (0);
	if (n == 0)
		p[0] = '0';
	p[b] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	while (n != 0 && b >= 0)
	{
		p[b-- - 1] = n % 10 + '0';
		n /= 10;
	}
	return (p);
}
