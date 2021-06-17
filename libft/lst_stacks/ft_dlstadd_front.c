/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:58:56 by josantos          #+#    #+#             */
/*   Updated: 2021/06/08 14:54:40 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst.h"

void	ft_dlstadd_front(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		new_node->next = temp;
		temp->prev = new_node;
	}
	*stack = new_node;
}
