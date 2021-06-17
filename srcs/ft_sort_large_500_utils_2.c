/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large_500_utils_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:20:29 by josantos          #+#    #+#             */
/*   Updated: 2021/06/17 23:32:15 by josantos         ###   ########.fr       */
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
