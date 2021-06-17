/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:38:11 by josantos          #+#    #+#             */
/*   Updated: 2021/02/17 16:51:39 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			a;

	a = 0;
	p = s;
	while (a < n)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return ((char *)s);
}
