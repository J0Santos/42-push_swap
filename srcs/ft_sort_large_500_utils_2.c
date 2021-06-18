/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large_500_utils_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:20:29 by josantos          #+#    #+#             */
/*   Updated: 2021/06/18 16:27:50 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_pos_check(t_stack *stack_a, int value)
{
	t_stack *temp;
	int pos;

	temp = NULL;
	pos = 0;
	temp = builder(stack_a);
	while (temp->next)
		if (temp->data == value)
			break;
		else
		{
			temp = temp->next;
			pos++;
		}
	temp = ft_dlst_last(temp);
	ft_dlst_clear(&temp);
	return (pos);
}

int	fake_median_min(t_stack *stack_a, int median)
{
	int fake_median;
	t_stack *temp;
	int i;
	int stop;

	i = 0;
	temp = NULL;
	temp = builder(stack_a);
	stop = position(temp, median) / 2;
	while (temp->data != median)
	{
		temp = temp->next;
		i++;
	}
	i = i / 2;
	while (i-- > 0)
		temp = temp->prev;
	fake_median = temp->data;
	temp = ft_dlst_last(temp);
	ft_dlst_clear(&temp);
	return (fake_median);
}

void	ft_sort_b_start(t_stack **stack_a, int min)
{
	int choice;
	int size;

	size = ft_dlst_size(*stack_a);
	choice = ft_rotate_choice_limits(*stack_a, size, min);
	while ((*stack_a)->data != min)
		if (choice == 1)
			ft_rotate_ra(stack_a);
		else
			ft_rrotate_rra(stack_a);
}
