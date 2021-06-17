/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:01:16 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 17:58:13 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			p;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	p = 0;
	while (n--)
	{
		*a = *b;
		p++;
		if (*b == (unsigned char)c)
			return ((char *)dst + p);
		a++;
		b++;
	}
	return (0);
}
