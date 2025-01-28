/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:35:08 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/28 13:39:51 by mivogel          ###   ########.fr       */
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

void	ft_insert(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if ((*stack_b)->index > (*stack_a)->index)
			ft_ra(stack_a);
		else
			ft_pa(stack_a, stack_b);
	}
}
