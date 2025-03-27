/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:46:33 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/14 10:46:33 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(stack_a, stack_b, 0);
	}
}

static void	r(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(stack_a, stack_b, 0);
	}
}

static void	rot_a(t_list **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ft_ra(stack, 0);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			ft_rra(stack, 0);
		}
	}
}

static void	rot_b(t_list **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ft_rb(stack, 0);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			ft_rrb(stack, 0);
		}
	}
}

void	ft_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		r(stack_a, stack_b, &cost_a, &cost_b);
	rot_a(stack_a, &cost_a);
	rot_b(stack_b, &cost_b);
	ft_pa(stack_a, stack_b, 0);
}
