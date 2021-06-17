/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstis_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:52:49 by josantos          #+#    #+#             */
/*   Updated: 2021/05/28 16:34:18 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst.h"

int	ft_dlstis_sorted_ascend(t_stack *stack)
{
	if (!stack)
		return (1);
	stack = ft_dlst_first(stack);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_dlstis_sorted_descend(t_stack *stack)
{
	if (!stack)
		return (1);
	stack = ft_dlst_first(stack);
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
