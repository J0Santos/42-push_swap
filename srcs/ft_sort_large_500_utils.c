/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large_500_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:22:23 by josantos          #+#    #+#             */
/*   Updated: 2021/06/18 12:51:06 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_b_500(t_stack **stack_b, t_stack **stack_a)
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

void	ft_presort_b_500(t_stack **stack_b, t_stack **stack_a, int median)
{
	int median_b;
	int size;
	
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

void	ft_presort_a_500(t_stack **stack_b, t_stack **stack_a, int count)
{
	int max;
	int size;
	int choice;
	bool rotate;
	int holder;

	holder = count;
	rotate = false;
	while (holder >= 1)
	{
		size = ft_dlst_size(*stack_b);
		max = ft_dlst_max(*stack_b);
		if ((*stack_b)->data == max)
		{
			ft_push_pa(stack_b, stack_a);
			rotate = false;
			holder--;
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
	while (count-- != 0)
	{
		ft_push_pb(stack_a, stack_b);
	}
}

int	fake_split_check(int split)
{
	int fake_split;
	static bool first = true;

	if (first == true)
	{
		fake_split = split / 2;
		first = false;
		return (fake_split);
	}
	else
		return (split);
}




int	ft_part_1(t_stack **stack_a, t_stack **stack_b)
{
	int median;
	int stopper;
	int size;
	int fake_median;
	int min;
	 bool rotate;
	int choice;

	rotate = false;
	median = ft_dlst_median(*stack_a);
	fake_median = fake_median_check(*stack_a, median);
	stopper = ft_pos_check(*stack_a, fake_median) 
		- ft_pos_check(*stack_a, median);
	size = ft_dlst_size(*stack_a);
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
			if (rotate == false)
			{
				choice = ft_rotate_choice(*stack_a, size, median);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
	}
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a);
	return (min);
}

int	ft_part_2(t_stack **stack_a, t_stack **stack_b, int min)
{
	int median;
	int size;
	int stopper;
	int choice;
	bool rotate;

	rotate = false;
	median = ft_dlst_median(*stack_a);
	stopper = (ft_pos_check(*stack_a, min) - ft_pos_check(*stack_a, median));
	size = ft_dlst_size(*stack_a);
	while (stopper > 1) 
	{
		if ((*stack_a)->data > median && (*stack_a)->data <= min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, median);
			stopper--;
			rotate = false;
		}
		else
			if (rotate == false)
			{
				choice = ft_rotate_choice(*stack_a, size, median);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
	}
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a);
	return (min);
}

int	ft_part_3(t_stack **stack_a, t_stack **stack_b, int min)
{
	int fake_median;
	int stopper;
	int size;
	int choice;
	bool rotate;
	int median;
	
	rotate = false;
	median = ft_dlst_median(*stack_a);
	fake_median = fake_median_min(*stack_a, median);
	stopper = (ft_pos_check(*stack_a, min) - ft_pos_check(*stack_a, fake_median));
	size = ft_dlst_size(*stack_a);
	while (stopper > 1)
	{
		if ((*stack_a)->data > fake_median && (*stack_a)->data <= min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, min);
			stopper--;
			rotate = false;
		}
		else
			if (rotate == false)
			{
				choice = ft_rotate_choice(*stack_a, size, median);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
	}
	min = ft_dlst_min(*stack_b);
	ft_sort_b_500(stack_b, stack_a);
	return (min);
}

void	ft_part_4(t_stack **stack_a, t_stack **stack_b, int min)
{
	int stopper;
	int size;
	int choice;
	bool rotate;
	int median;

	rotate = false;
	median = ft_dlst_median(*stack_a);
	stopper = ft_pos_check(*stack_a, min);
	size = ft_dlst_size(*stack_a);
	while (stopper > 1)
	{
		if ((*stack_a)->data < min)
		{
			ft_push_pb(stack_a, stack_b);
			ft_presort_b_500(stack_b, stack_a, min);
			stopper--;
			rotate = false;
		}
		else
			if (rotate == false)
			{
				choice = ft_rotate_choice(*stack_a, size, median);
				rotate = true;
			}
			if (choice == 1)
				ft_rotate_ra(stack_a);
			else
				ft_rrotate_rra(stack_a);
	}
	ft_sort_b_500(stack_b, stack_a);
}
