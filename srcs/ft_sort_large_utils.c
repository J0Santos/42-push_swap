/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large_500_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:22:23 by josantos          #+#    #+#             */
/*   Updated: 2021/06/18 18:44:46 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_b_500(t_stack **stack_b, t_stack **stack_a, int min)
{
	int		size;
	int		max;
	bool	rotate;
	int		choice;

	rotate = false;
	ft_sort_b_start(stack_a, min);
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

void	ft_presort_b_500(t_stack **stack_b, t_stack **stack_a, int median)
{
	int	median_b;
	int	size;
	
	size = ft_dlst_size(*stack_a);
	median_b = ft_dlst_median(*stack_b);
	if ((*stack_b)->next)
		if ((*stack_b)->data < median_b)
		{
			if ((*stack_a)->data < median)
				ft_rotate_rr(stack_a, stack_b);
			else
				ft_rotate_rb(stack_b);
		}
	if ((*stack_b)->next && (*stack_b)->data > (*stack_b)->next->data)
			ft_swap_sb(*stack_b);
}

int	ft_part_1(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	int		stopper;
	int		fake_median;
	int		min;
	bool	rotate;
	int		choice;

	rotate = false;
	median = ft_dlst_median(*stack_a);
	fake_median = fake_median_check(*stack_a, median);
	stopper = ft_pos_check(*stack_a, fake_median) 
		- ft_pos_check(*stack_a, median);
	while (stopper > 1)
	{
		if ((*stack_a)->data > fake_median)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, median);
			stopper--;
			rotate = false;
		}
		else
		{
			if (rotate == false)
			{
				choice = ft_rotate_choice(*stack_a, fake_median);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
		}
	}
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a, (*stack_a)->data);
	return (min);
}

int	ft_part_2(t_stack **stack_a, t_stack **stack_b, int min)
{
	int		median;
	int		stopper;
	int		choice;
	bool	rotate;

	rotate = false;
	median = ft_dlst_median(*stack_a);
	stopper = (ft_pos_check(*stack_a, min) - ft_pos_check(*stack_a, median));
	while (stopper > 0) 
	{
		if ((*stack_a)->data >= median && (*stack_a)->data < min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, median);
			stopper--;
			rotate = false;
		}
		else
		{
			if (rotate == false)
			{
				choice = ft_rotate_choice_2(*stack_a, median, min);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
		}
	}
	choice = min;
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a, choice);
	return (min);
}

int	ft_part_3(t_stack **stack_a, t_stack **stack_b, int min)
{
	int		fake_median;
	int		stopper;
	int		choice;
	bool	rotate;
	int		median;
	
	rotate = false;
	median = ft_dlst_median(*stack_a);
	fake_median = fake_median_min(*stack_a, median);
	stopper = (ft_pos_check(*stack_a, min) - ft_pos_check(*stack_a, fake_median));
	while (stopper > 0)
	{
		if ((*stack_a)->data >= fake_median && (*stack_a)->data < min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, min);
			stopper--;
			rotate = false;
		}
		else
		{
			if (rotate == false)
			{
				choice = ft_rotate_choice_2(*stack_a, fake_median, min);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
		}
	}
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a, (*stack_a)->data);
	return (min);
}

void	ft_part_4(t_stack **stack_a, t_stack **stack_b, int min)
{
	int		stopper;
	int		choice;
	bool	rotate;
	int		median;

	rotate = false;
	median = ft_dlst_median(*stack_a);
	stopper = ft_pos_check(*stack_a, min);
	while (stopper > 0)
	{
		if ((*stack_a)->data < min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, min);
			stopper--;
			rotate = false;
		}
		else
		{
			if (rotate == false)
			{
				choice = ft_rotate_choice_3(*stack_a, min);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
		}
	}
	ft_sort_b_500(stack_b, stack_a, min);
}