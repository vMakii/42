/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:35:08 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/18 15:55:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pushb(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a / 2)
	{
		if ((*stack_a)->index <= size_a / 2)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		i++;
	}
	while (i + 3 < size_a)
	{
		ft_pb(stack_a, stack_b);
		i++;
	}
}

void	ft_bigsort(t_list **stack_a, t_list **stack_b, int size_a)
{
	ft_pushb(stack_a, stack_b, size_a);
	ft_sort3(stack_a);
}
