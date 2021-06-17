/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:12:11 by josantos          #+#    #+#             */
/*   Updated: 2021/06/17 19:17:51 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	fake_sort(t_stack **stack)
{
	int temp;

	if (*stack)
		while (ft_dlstis_sorted_ascend(*stack) != 1)
		{
			while ((*stack)->next)
			{
				if ((*stack)->data > (*stack)->next->data)
				{
					temp = (*stack)->data;
					(*stack)->data = (*stack)->next->data;
					(*stack)->next->data = temp;
				}
				*stack = (*stack)->next;
			}
			*stack = ft_dlst_first(*stack);
		}
}

static t_stack	*builder(t_stack *stack)
{
	t_stack *temp;

	temp = NULL;
	while (stack)
	{
		build_stack(stack->data, &temp);
		stack = stack->next;
	}
	fake_sort(&temp);
	return (temp);
}

int	ft_dlst_median(t_stack *stack)
{
	int median;
	int size;
	int i;
	t_stack *temp;

	i = 1;
	temp = builder(stack);
	size = ft_dlst_size(stack);
	stack = ft_dlst_first(stack);
	while (i++ <= (size / 2))
		temp = temp->next;
	median = temp->data;
	temp = ft_dlst_last(temp);
	ft_dlst_clear(&temp);
	return (median);
}

int	fake_median_check(t_stack *stack_a, int median)
{
	static bool first = true;
	int fake_median;
	t_stack *temp;
	int i;

	i = 0;
	if (first == true)
	{
		temp = builder(stack_a);
		while (i++ <= (median / 2))
			temp = temp->next;
		fake_median = temp->data;
		temp = ft_dlst_last(temp);
		ft_dlst_clear(&temp);
		first = false;
		return (fake_median);
	}
	else
		return (median);
}
