/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:01:50 by josantos          #+#    #+#             */
/*   Updated: 2021/06/16 13:26:13 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_b(t_stack **stack_b, t_stack **stack_a)
{
	int size;
	int max;
	bool rotate;
	int choice;

	rotate = false;
	while (*stack_b)
	{
		size = ft_dlst_size(*stack_b);
		max = ft_dlst_max(*stack_b);
		if ((*stack_b)->data == max)
		{
			ft_push_pa(stack_b, stack_a);
			rotate = false;
		}
		else
		{
			if (rotate == false)
			{
				choice = ft_rotate_choice_limits(*stack_b, size, max);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_rb(stack_b);
			else
				ft_rrotate_rrb(stack_b);
		}
	}
}

void	ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int median;
	bool rotate;
	int choice;

	choice = -1;
	rotate = false;
	while (*stack_a)
	{
		median = ft_dlst_median(*stack_a);
		if ((*stack_a)->data <= median)
		{
			ft_push_pb(stack_a, stack_b);
			rotate = false;
		}
		else
		{
			if (rotate == false)
			{
				size = ft_dlst_size(*stack_a);
				choice = ft_rotate_choice(*stack_a, size, median);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
		}
	}
}

void	ft_presort_b(t_stack **stack_b, t_stack **stack_a)
{
	int median;

	if ((*stack_b)->next != NULL)
	{
		median = ft_dlst_median(*stack_b);
		if ((*stack_b)->data < median)
			ft_rotate_rb(stack_b);
		if ((*stack_b)->data < (*stack_b)->next->data)
		{
			if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->next)
				ft_swap_ss(*stack_a, *stack_b);
			else
				ft_swap_sb(*stack_b);
		}
	}
}
