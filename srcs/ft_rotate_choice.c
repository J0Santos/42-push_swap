/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_choice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:04:25 by josantos          #+#    #+#             */
/*   Updated: 2021/06/15 14:42:58 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_position(t_stack *stack, int median)
{
	int pos;

	pos = 1;
	while (stack->next)
		if (stack->data > median)
			break ;
		else
		{
			stack = stack->next;
			pos++;
		}
	return (pos);
}

int	ft_rotate_choice(t_stack *stack, int size, int median)
{
	int pos;

	pos = ft_position(stack, median);
	if (pos > (size / 2))
		return (0);
	else
		return (1);
}

static int	ft_position_limits(t_stack *stack, int limit)
{
	int pos;

	pos = 1;
	while (stack->next)
		if (stack->data == limit)
			break ;
		else
		{
			stack = stack->next;
			pos++;
		}
	return (pos);
}

int	ft_rotate_choice_limits(t_stack *stack, int size, int limit)
{
	int pos;

	pos = ft_position_limits(stack, limit);
	if (pos >= (size / 2))
		return (0);
	else
		return (1);
}
