/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:35:08 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/29 13:26:13 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushb(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;
	int	push;

	i = 0;
	push = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_b, stack_a);
			push++;
		}
		else
			ft_ra(stack_a);
		i++;
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
		if (cost < cheapest)
		{
			cheapest = cost;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_move(stack_a, stack_b, cost_a, cost_b);
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	ft_pushb(stack_a, stack_b, size);
	ft_sort3(stack_a);
	while (*stack_b)
	{
		size = ft_lstsize(*stack_a);
		ft_target(stack_a, stack_b);
		ft_cost(stack_a, stack_b, size);
		ft_solve(stack_a, stack_b);
	}
}
