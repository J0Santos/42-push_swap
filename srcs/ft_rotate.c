/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:38:33 by josantos          #+#    #+#             */
/*   Updated: 2021/06/09 17:51:26 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	if (!stack)
		return ;
	*stack = ft_dlst_first(*stack);
	(*stack)->next->prev = NULL;
	ft_dlstadd_back(stack, ft_dlst_new((*stack)->data));
	ft_dlst_remove(stack);
	*stack = ft_dlst_first(*stack);
}

void	ft_rotate_ra(t_stack **stack_a)
{
	ft_putstr_fd("ra", 1);
	ft_putstr_fd("\n", 1);
	ft_rotate(stack_a);
}

void	ft_rotate_rb(t_stack **stack_b)
{
	ft_putstr_fd("rb", 1);
	ft_putstr_fd("\n", 1);
	ft_rotate(stack_b);
}

void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("rr", 1);
	ft_putstr_fd("\n", 1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
