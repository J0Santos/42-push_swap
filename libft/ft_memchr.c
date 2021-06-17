/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:53:24 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 17:59:27 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[a] == (unsigned char)c)
			return (((unsigned char *)s) + a);
		a++;
		n--;
	}
	return (NULL);
}
