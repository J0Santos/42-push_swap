/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:45:45 by josantos          #+#    #+#             */
/*   Updated: 2021/02/22 15:34:30 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;

	a = 0;
	if (s1 == 0)
		return (0);
	while (ft_strchr(set, s1[a]) && s1[a] != '\0')
		a++;
	b = (ft_strlen(s1) - 1);
	while (ft_strchr(set, s1[b]) && b > a)
		b--;
	return (ft_substr(s1, a, b - a + 1));
}
