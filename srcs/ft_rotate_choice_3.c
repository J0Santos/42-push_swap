/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_choice_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:58:06 by josantos          #+#    #+#             */
/*   Updated: 2021/06/22 20:53:21 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_position_down(t_stack *stack, int median)
{
	int	pos;

	pos = 1;
	while (stack->next)
	{
		if (stack->data < median)
			break ;
		else
		{
			stack = stack->next;
			pos++;
		}
	}
	return (pos);
}

static int	ft_position_up(t_stack *stack, int median)
{
	int	pos;

	pos = 1;
	stack = ft_dlst_last(stack);
	while (stack->prev)
	{
		if (stack->data < median)
			break ;
		else
		{
			stack = stack->prev;
			pos++;
		}
	}
	return (pos);
}

int	ft_rotate_choice_3(t_stack *stack, int median)
{
	int	pos_down;
	int	pos_up;

	pos_down = ft_position_down(stack, median);
	pos_up = ft_position_up(stack, median);
	if (pos_up < pos_down)
		return (0);
	else
		return (1);
}

static int	ft_position_limits_medium(t_stack *stack, int limit)
{
	int	pos;

	pos = 1;
	while (stack->next)
	{
		if (stack->data == limit)
			break ;
		else
		{
			stack = stack->next;
			pos++;
		}
	}
	return (pos);
}

int	ft_rotate_choice_limits_medium(t_stack *stack, int min)
{
	int	pos;
	int	size;

	size = ft_dlst_size(stack);
	pos = ft_position_limits_medium(stack, min);
	if (pos > size / 2)
		return (0);
	else
		return (1);
}
