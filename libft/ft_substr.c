/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:43:52 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 16:55:16 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_malloc(const char *s, size_t len)
{
	char	*p;

	if (len >= ft_strlen(s))
	{
		p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!p)
			return (0);
	}
	else
	{
		p = (char *)malloc(sizeof(char) * len + 1);
		if (!p)
			return (0);
	}
	return (p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*p;

	a = 0;
	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	p = do_malloc(s, len);
	while (s[a] && a < len)
	{
		p[a++] = s[start++];
	}
	p[a] = '\0';
	return (p);
}
