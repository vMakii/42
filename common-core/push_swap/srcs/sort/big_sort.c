/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:35:08 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/11 15:46:31 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushb(t_list **stack_a, t_list **stack_b, int size)
{
	int	push;

	push = 0;
	while (size > 6 && push < size * 2 / 3)
	{
		if ((*stack_a)->index <= size / 3)
		{
			ft_pb(stack_b, stack_a);
			ft_rb(stack_b);
			push++;
		}
		else if ((*stack_a)->index <= size * 2 / 3)
		{
			ft_pb(stack_b, stack_a);
			push++;
		}
		else
			ft_ra(stack_a);
	}
	while (size - push > 3)
	{
		ft_pb(stack_b, stack_a);
		push++;
	}
}

static void	ft_solve(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (cost < ft_abs(cheapest))
		{
			cheapest = cost;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_move(stack_a, stack_b, cost_a, cost_b);
}

static void	double_rotor(t_list **stack_a)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if ((*stack_a)->index > size / 2)
	{
		while (!ft_is_sorted(*stack_a))
			ft_ra(stack_a);
	}
	else
	{
		while (!ft_is_sorted(*stack_a))
			ft_rra(stack_a);
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	ft_pushb(stack_a, stack_b, size);
	ft_sort3(stack_a);
	while (*stack_b)
	{
		size = ft_lstsize(*stack_a);
		ft_target(stack_a, stack_b);
		ft_cost(stack_b, size);
		ft_solve(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		double_rotor(stack_a);
}
