/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:42:11 by josantos          #+#    #+#             */
/*   Updated: 2021/06/22 17:29:34 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_lst.h"

t_stack	*ft_dlst_new(int content)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (0);
	temp->data = content;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}
