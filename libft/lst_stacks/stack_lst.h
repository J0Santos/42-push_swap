/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:09:53 by josantos          #+#    #+#             */
/*   Updated: 2021/06/09 16:36:12 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_LST_H
# define STACK_LST_H

# include "../libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_dlst_first(t_stack *stack);
t_stack	*ft_dlst_last(t_stack *stack);
t_stack	*ft_dlst_new(int content);
int		ft_dlst_size(t_stack *stack);
void	ft_dlstadd_back(t_stack **lst, t_stack *new_node);
void	ft_dlstadd_front(t_stack **stack, t_stack *new_node);
int		ft_dlsis_dup(t_stack *stack);
int		ft_dlstis_sorted_ascend(t_stack *stack);
int		ft_dlstis_sorted_descend(t_stack *stack);
int		ft_dlst_max(t_stack *stack);
int		ft_dlst_min(t_stack *stack);
void	ft_dlst_remove(t_stack **stack);
void	ft_dlst_clear(t_stack **stack);
void	ft_dlst_print(t_stack *stack);

#endif
