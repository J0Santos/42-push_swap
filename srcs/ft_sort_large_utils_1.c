/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large_500_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:22:23 by josantos          #+#    #+#             */
/*   Updated: 2021/06/18 20:04:49 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_part_1(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	int		fake_median;
	int		min;

	median = ft_dlst_median(*stack_a);
	fake_median = fake_median_check(*stack_a, median);
	ft_part_1_cont(stack_a, stack_b, fake_median, median);
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a, (*stack_a)->data);
	return (min);
}

void	ft_part_1_cont(t_stack **stack_a, t_stack **stack_b, int fake_median,
			int median)
{
	int	stopper;
	int	comp_val;

	if (ft_dlst_size(*stack_a) % 4 != 0)
		comp_val = 0;
	else
		comp_val = 1;
	stopper = ft_pos_check(*stack_a, fake_median)
		- ft_pos_check(*stack_a, median);
	while (stopper > comp_val)
	{
		if ((*stack_a)->data > fake_median)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, median);
			stopper--;
		}
		else
		{
			if (ft_rotate_choice(*stack_a, fake_median) == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
		}
	}
}

int	ft_part_2(t_stack **stack_a, t_stack **stack_b, int min)
{
	int		median;
	int		stopper;
	int		prev_min;

	median = ft_dlst_median(*stack_a);
	stopper = (ft_pos_check(*stack_a, min) - ft_pos_check(*stack_a, median));
	while (stopper > 0)
	{
		if ((*stack_a)->data >= median && (*stack_a)->data < min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, median);
			stopper--;
		}
		else
			if (ft_rotate_choice_2(*stack_a, median, min) == 1)
				ft_rotate_ra(stack_a);
		else
			ft_rrotate_rra(stack_a);
	}
	prev_min = min;
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a, prev_min);
	return (min);
}

int	ft_part_3(t_stack **stack_a, t_stack **stack_b, int min)
{
	int		fake_median;
	int		stopper;
	int		median;

	median = ft_dlst_median(*stack_a);
	fake_median = fake_median_min(*stack_a, median);
	stopper = (ft_pos_check(*stack_a, min)
			- ft_pos_check(*stack_a, fake_median));
	while (stopper > 0)
	{
		if ((*stack_a)->data >= fake_median && (*stack_a)->data < min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, min);
			stopper--;
		}
		else
			if (ft_rotate_choice_2(*stack_a, fake_median, min) == 1)
				ft_rotate_ra(stack_a);
		else
			ft_rrotate_rra(stack_a);
	}
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a, (*stack_a)->data);
	return (min);
}

void	ft_part_4(t_stack **stack_a, t_stack **stack_b, int min)
{
	int		stopper;
	int		median;

	median = ft_dlst_median(*stack_a);
	stopper = ft_pos_check(*stack_a, min);
	while (stopper > 0)
	{
		if ((*stack_a)->data < min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, min);
			stopper--;
		}
		else
			if (ft_rotate_choice_3(*stack_a, min) == 1)
				ft_rotate_ra(stack_a);
		else
			ft_rrotate_rra(stack_a);
	}
	ft_sort_b_500(stack_b, stack_a, min);
}
