/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstis_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:09:17 by josantos          #+#    #+#             */
/*   Updated: 2021/05/24 12:57:43 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst.h"

int	ft_dlstis_dup(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->data == stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}
