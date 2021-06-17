/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:05:05 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 16:55:38 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;
	int	b;

	a = 0;
	b = ft_strlen(s);
	while (b >= 0)
	{
		if (s[b] == (char)c)
			return (((char *)s) + b);
		b--;
	}
	return (0);
}
