/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:41:00 by josantos          #+#    #+#             */
/*   Updated: 2021/06/17 11:41:23 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort(t_stack **stack)
{
	int i;
	t_stack *stack_b;
	
	stack_b = NULL;
	i = ft_dlst_size(*stack);
	if (ft_dlstis_sorted_ascend(*stack) == 0)
	{
		if (i <= 3)
			ft_sort_small(stack);
		else if (i <= 5)
		ft_sort_medium(stack);
		else if (i > 5 && i <= 100)
			ft_sort_large_100(stack);
		else
			ft_sort_large_500(stack);
	}
}

void	ft_sort_small(t_stack **stack)
{
	int	max;
	int min;
	int sorted;

	max = ft_dlst_max(*stack);
	min = ft_dlst_min(*stack);
	*stack = ft_dlst_first(*stack);
	sorted = 0;
	while (sorted != 1)
	{
		if ((*stack)->data == max)
			ft_rotate_ra(stack);
		if ((*stack)->data > (*stack)->next->data)
			ft_swap_sa(*stack);
		if ((*stack)->data != min)
			ft_rrotate_rra(stack);
		if (ft_dlstis_sorted_ascend(*stack) == 1)
			break ;
		else if ((*stack)->data == min)
			ft_rrotate_rra(stack);
		sorted = ft_dlstis_sorted_ascend(*stack);
	}
}

void	ft_sort_medium(t_stack **stack_a)
{
	int min;
	int sorted;
	int i;
	t_stack *stack_b;

	sorted = 0;
	i = 0;
	stack_b = NULL;
	while (i < 2)
	{
		min = ft_dlst_min(*stack_a);
		*stack_a = ft_dlst_first(*stack_a);
		if ((*stack_a)->data == min)
		{
			ft_push_pb(stack_a, &stack_b);
			i++;
		}
		else
			ft_rotate_ra(stack_a);
	}
	ft_sort_small(stack_a);
	while (stack_b)
		ft_push_pa(&stack_b, stack_a);
}

void	ft_sort_large_100(t_stack **stack)
{

	int size;
	t_stack *stack_b;
	int median;

	stack_b = NULL;
	while (ft_dlst_size(*stack) > 17)
	{
		size = ft_dlst_size(*stack);
		median = ft_dlst_median(*stack);
		if ((*stack)->data < median)
		{
			ft_push_pb(stack, &stack_b);
			ft_presort_b(&stack_b, stack);
		}
		else
			if (ft_rotate_choice(*stack, size, median) == 0)
				ft_rotate_ra(stack);
			else
				ft_rrotate_rra(stack);
	}
	ft_sort_a(stack, &stack_b);
	ft_sort_b(&stack_b, stack);
}

void	ft_sort_large_500(t_stack **stack_a)
{
	t_stack *stack_b;
	int min;
	int count;

	stack_b = NULL;
	count = 0;
	min = 0;
	min = ft_part_1(stack_a, &stack_b);
	min = ft_part_2(stack_a, &stack_b, min);
	min = ft_part_3(stack_a, &stack_b, min);
	ft_part_4(stack_a, &stack_b, min);
}
/*void	ft_sort_large_500(t_stack **stack_a)
{
	t_stack *stack_b;
	int median;
	int size;
	int split;
	int count;

	count = 0;
	stack_b = NULL;
	while (*stack_a)
	{
		if (ft_dlst_size(*stack_a) == 1)
		{
			ft_push_pb(stack_a, &stack_b);
			break;
		}
		size = ft_dlst_size(*stack_a);
		split = size / 2;
		median = ft_dlst_median(*stack_a);
		split = fake_split_check(split);
		median = fake_median_check(*stack_a, median, split);
		while (split >= 1)
		{
			if ((*stack_a)->data < median)
			{
				ft_push_pb(stack_a, &stack_b);
				ft_presort_b_500(&stack_b, stack_a, median);
				split--;
				count++;
			}
			else
				if (ft_rotate_choice(*stack_a, size, median) == 0)
					ft_rotate_ra(stack_a);
				else
					ft_rrotate_rra(stack_a);
			if (count == 125)
			{
				ft_presort_a_500(&stack_b, stack_a, count);
				count = 0;
			}
		}
	}
	ft_sort_b_500(&stack_b, stack_a);
}*/
