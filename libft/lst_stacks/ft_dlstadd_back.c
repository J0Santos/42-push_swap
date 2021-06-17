/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:00:16 by josantos          #+#    #+#             */
/*   Updated: 2021/06/09 16:36:14 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst.h"

void	ft_dlstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!*stack)
		*stack = new_node;
	else
	{
		last = ft_dlst_last(*stack);
		new_node->prev = last;
		last->next = new_node;
	}
}

