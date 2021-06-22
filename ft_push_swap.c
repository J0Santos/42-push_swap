/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:34:54 by josantos          #+#    #+#             */
/*   Updated: 2021/06/22 17:28:58 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	build_stack(int input, t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		*stack = ft_dlst_new(input);
	else
	{
		temp = ft_dlst_new(input);
		ft_dlstadd_back(stack, temp);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	ft_error_check(argc, argv);
	while (i < argc)
	{
		build_stack(ft_atoi(argv[i]), &stack_a);
		i++;
	}
	ft_sort(&stack_a, &stack_b);
	ft_dlst_clear(&stack_a);
	ft_dlst_clear(&stack_b);
	return (0);
}
