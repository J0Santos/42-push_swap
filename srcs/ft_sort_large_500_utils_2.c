/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large_500_utils_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:20:29 by josantos          #+#    #+#             */
/*   Updated: 2021/06/16 17:56:10 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_mid_sort(t_stack **stack_b, t_stack **stack_a, int size)
{
	int max;
	int counter;
	int choice;
	bool rotate;

	counter = 0;
	rotate = false;
	while (*stack_b)
	{
		max = ft_dlst_max(*stack_b);
		if ((*stack_b)->data == max)
		{
			ft_push_pa(stack_b, stack_a);
			counter++;
			rotate = false;
		}
		else
		{
			if (rotate == false)
			{
				choice = ft_rotate_choice_limits(*stack_b, size, max);
				rotate = true;
			}
			if (choice  == 1)
				ft_rotate_rb(stack_b);
			else
				ft_rrotate_rrb(stack_b);
		}
	}
}
