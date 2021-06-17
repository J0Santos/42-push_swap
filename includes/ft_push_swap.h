/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:29:43 by josantos          #+#    #+#             */
/*   Updated: 2021/06/17 23:32:13 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

void	build_stack(int input, t_stack **stack);
void	ft_swap_sa(t_stack *stack);
void	ft_swap_sb(t_stack *stack);
void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate_ra(t_stack **stack_a);
void	ft_rotate_rb(t_stack **stack_b);
void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrotate_rra(t_stack **stack_a);
void	ft_rrotate_rrb(t_stack **stack_b);
void	ft_rrotate_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_push_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_push_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_error_check(int counter, char **str);
void	ft_sort(t_stack **stack);
int		ft_dlst_median(t_stack *stack);
int		fake_median_check(t_stack *stack_a, int median);
int		fake_split_check(int split);
void	ft_sort_small(t_stack **stack);
void	ft_sort_medium(t_stack **stack);
void	ft_sort_large_100(t_stack **stack);
void	ft_sort_large_500(t_stack **stack);
int		ft_rotate_choice(t_stack *stack, int size, int median);
int		ft_rotate_choice_limits(t_stack *stack, int size, int limit);
void	first_half(t_stack **stack, t_stack **stack_b, int size);
void	second_half(t_stack **stack, t_stack **stack_b, int size);
void	ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_a_500(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_b_500(t_stack **stack_b, t_stack **stack_a);
void	ft_sort_b(t_stack **stack_b, t_stack **stack_a);
void	ft_presort_b(t_stack **stack_b, t_stack **stack_a);
void	ft_presort_a_500(t_stack **stack_b, t_stack **stack_a, int count);
void	ft_presort_b_500(t_stack **stack_b, t_stack **stack_a, int median);
void	ft_split_b(t_stack **stack_b, t_stack **stack_a);

int		ft_part_1(t_stack **stack_a, t_stack **stack_b);
int		ft_part_2(t_stack **stack_a, t_stack **stack_b, int min);
int		ft_part_3(t_stack **stack_a, t_stack **stack_b, int min);
void	ft_part_4(t_stack **stack_a, t_stack **stack_b, int min);
t_stack	*builder(t_stack *stack);
int		ft_pos_check(t_stack *stack_a, int value);

#endif
