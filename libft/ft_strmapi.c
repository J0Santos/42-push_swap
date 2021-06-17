/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:18:23 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 16:57:42 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	unsigned int	b;
	char			*p;

	if (!s || !f)
		return (NULL);
	a = 0;
	b = ft_strlen(s);
	p = (char *)ft_calloc(b + 1, sizeof(char));
	if (!p)
		return (0);
	while (s[a])
	{
		p[a] = f(a, s[a]);
		a++;
	}
	return (p);
}
