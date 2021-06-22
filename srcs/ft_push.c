/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:36:26 by josantos          #+#    #+#             */
/*   Updated: 2021/06/22 18:01:03 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_push(t_stack **stack1, t_stack **stack2)
{
	if (!stack1)
		return ;
	ft_dlstadd_front(stack2, ft_dlst_new((*stack1)->data));
	ft_dlst_remove(stack1);
}

void	ft_push_pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_putstr_fd("pa\n", 1);
	ft_push(stack_b, stack_a);
}

void	ft_push_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("pb\n", 1);
	ft_push(stack_a, stack_b);
}
