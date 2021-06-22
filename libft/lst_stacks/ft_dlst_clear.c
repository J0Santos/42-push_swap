/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:52:48 by josantos          #+#    #+#             */
/*   Updated: 2021/06/22 17:33:00 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst.h"

void	ft_dlst_clear(t_stack **stack)
{
	if (!*stack)
		return ;
	while (*stack)
		ft_dlst_remove(stack);
}
