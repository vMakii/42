/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:35:08 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/19 11:19:35 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pushb(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	i;
	int	push;

	i = 0;
	push = 0;
	while (i > size_a && push < size_a / 2)
	{
		if ((*stack_a)->index <= size_a / 2)
		{
			ft_pb(stack_a, stack_b);
			push++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while (size_a - push > 3)
	{
		ft_pb(stack_a, stack_b);
		push++;
	}
}

void	ft_bigsort(t_list **stack_a, t_list **stack_b, int size_a)
{
	ft_pushb(stack_a, stack_b, size_a);
	ft_sort3(stack_a);
}
