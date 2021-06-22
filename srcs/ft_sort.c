/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:41:00 by josantos          #+#    #+#             */
/*   Updated: 2021/06/22 13:58:04 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	i = ft_dlst_size(*stack_a);
	if (ft_dlstis_sorted_ascend(*stack_a) == 0)
	{
		if (i <= 3)
			ft_sort_small(stack_a);
		else if (i <= 5)
			ft_sort_medium(stack_a, stack_b);
		else
			ft_sort_large_500(stack_a, stack_b);
	}
}

void	ft_sort_small(t_stack **stack)
{
	int	max;
	int	min;
	int	sorted;

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

void	ft_sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		sorted;
	int		i;

	sorted = 0;
	i = 0;
	while (i < 2)
	{
		min = ft_dlst_min(*stack_a);
		*stack_a = ft_dlst_first(*stack_a);
		if ((*stack_a)->data == min)
		{
			ft_push_pb(stack_a, stack_b);
			i++;
		}
		else
			ft_rotate_ra(stack_a);
	}
	ft_sort_small(stack_a);
	while (stack_b)
		ft_push_pa(stack_b, stack_a);
}

void	ft_sort_large_500(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		count;

	count = 0;
	min = 0;
	min = ft_part_1(stack_a, stack_b);
	min = ft_part_2(stack_a, stack_b, min);
	min = ft_part_3(stack_a, stack_b, min);
	ft_part_4(stack_a, stack_b, min);
}
