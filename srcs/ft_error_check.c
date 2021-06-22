/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:24:56 by josantos          #+#    #+#             */
/*   Updated: 2021/06/22 20:52:34 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_checkdigit(char *str)
{
	int	i;
	int	a;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) >= 2)
		i++;
	while (str[i])
	{
		a = ft_isdigit(str[i]);
		if (a == 0)
			return (a);
		i++;
	}
	return (a);
}

static int	ft_checkint(char *str)
{
	long long	i;

	i = ft_atoll(str);
	if (i > 2147483647 || i < -2147483648)
		return (0);
	return (1);
}

static int	ft_isdup(char **argv, int argc, int i, t_stack **checker)
{
	int		holder;
	t_stack	*holds_head;

	while (++i < argc)
		build_stack(ft_atoi(argv[i]), checker);
	holds_head = *checker;
	while (holds_head->next)
	{
		holder = (*checker)->data;
		while ((*checker)->next)
		{
			if (holder == (*checker)->next->data)
			{
				ft_dlst_clear(checker);
				return (1);
			}
			else
				*checker = (*checker)->next;
		}
		holds_head = holds_head->next;
		*checker = holds_head;
	}
	ft_dlst_clear(checker);
	return (0);
}

void	ft_error_check(int argc, char **argv, int i)
{
	t_stack	*checker;

	checker = NULL;
	if (argc == 1)
		exit(0);
	while (i <= argc - 1)
	{
		if (ft_checkdigit(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		if (ft_checkint(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (ft_isdup(argv, argc, 0, &checker) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}
