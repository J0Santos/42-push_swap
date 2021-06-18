/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:54:28 by josantos          #+#    #+#             */
/*   Updated: 2021/06/18 18:37:32 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_rrotate(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = ft_dlst_last(*stack);
	temp->prev->next = NULL;
	ft_dlstadd_front(stack, ft_dlst_new(temp->data));
	ft_dlst_remove(&temp);
}

void	ft_rrotate_rra(t_stack **stack)
{
	ft_putstr_fd("rra\n", 1);
	ft_rrotate(stack);
}

void	ft_rrotate_rrb(t_stack **stack)
{
	ft_putstr_fd("rrb\n", 1);
	ft_rrotate(stack);
}

void	ft_rrotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("rrr\n", 1);
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}
