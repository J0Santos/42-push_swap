/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:31:53 by josantos          #+#    #+#             */
/*   Updated: 2021/05/21 13:34:54 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst.h"

t_stack	*ft_dlst_first(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}
