/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:25:07 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 16:58:52 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (dst[a] && a < dstsize)
		a++;
	while (src[b] && (a + b + 1) < dstsize)
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a < dstsize)
		dst[a + b] = '\0';
	return (a + ft_strlen(src));
}
