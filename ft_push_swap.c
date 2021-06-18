/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:34:54 by josantos          #+#    #+#             */
/*   Updated: 2021/06/18 17:44:13 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	build_stack(int input, t_stack **stack)
{
	t_stack	*temp;

	temp = ft_dlst_new(input);
	if (*stack == NULL)
		*stack = ft_dlst_new(input);
	else
		ft_dlstadd_back(stack, temp);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	ft_error_check(argc, argv);
	while (i < argc)
	{
		build_stack(ft_atoi(argv[i]), &stack);
		i++;
	}
	ft_sort(&stack);
	return (0);
}
