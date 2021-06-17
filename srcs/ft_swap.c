/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:21:27 by josantos          #+#    #+#             */
/*   Updated: 2021/05/28 15:27:02 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int temp;

	stack = ft_dlst_first(stack);
	if (stack->next == NULL || !stack)
		return ;
	{
		temp = stack->next->data;
		stack->next->data = stack->data;
		stack->data = temp;
	}
	stack = ft_dlst_first(stack);
}
void	ft_swap_sa(t_stack *stack_a)
{
	ft_putstr_fd("sa\n", 1);
	ft_swap(stack_a);
}

void	ft_swap_sb(t_stack *stack_b)
{
	ft_putstr_fd("sb\n", 1);
	ft_swap(stack_b);
}

void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("ss\n", 1);
	ft_swap(stack_a);
	ft_swap(stack_b);
}

