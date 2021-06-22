/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:24:22 by josantos          #+#    #+#             */
/*   Updated: 2021/06/22 17:32:57 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst.h"

void	ft_dlst_remove(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!*stack)
		return ;
	if (temp->next)
		temp->next->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->prev)
		*stack = temp->prev;
	else
		*stack = temp->next;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp);
	temp = NULL;
}
