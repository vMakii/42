/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:46:33 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/29 13:52:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(stack_a, stack_b);
	}
}

static void	r(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(stack_a, stack_b);
	}
}

static void	rota(t_list **stack_a, int *cost_a)
{
}

void	ft_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		r(stack_a, stack_b, &cost_a, &cost_b);
	if (cost_a != 0)
		rot_a(stack_a, &cost_a);
	if (cost_b != 0)
		rot_b(stack_b, &cost_a);
	pa(stack_a, stack_b);
}
