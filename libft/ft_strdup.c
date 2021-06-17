/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:41:44 by josantos          #+#    #+#             */
/*   Updated: 2021/04/01 17:00:54 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*p;
	int			a;

	a = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (0);
	while (s1[a])
	{
		((char *)p)[a] = ((char *)s1)[a];
		a++;
	}
	((char *)p)[a] = '\0';
	return ((char *)p);
}
