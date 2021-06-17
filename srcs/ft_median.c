/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:12:11 by josantos          #+#    #+#             */
/*   Updated: 2021/06/15 14:14:30 by josantos         ###   ########.fr       */
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

int	ft_dlst_median(t_stack *stack)
{
	int median;
	int size;
	int i;
	t_stack *temp;

	i = 1;
	temp = NULL;
	size = ft_dlst_size(stack);
	stack = ft_dlst_first(stack);
	while (stack)
	{
		build_stack(stack->data, &temp);
		stack = stack->next;
	}
	fake_sort(&temp);
	while (i++ <= (size / 2))
		temp = temp->next;
	median = temp->data;
	temp = ft_dlst_last(temp);
	ft_dlst_clear(&temp);
	return (median);
}
