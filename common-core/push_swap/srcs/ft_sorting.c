/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:29 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/17 14:59:55 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
		{
			ft_printf("not sorted!\n");
			return (0);
		}
		head = head->next;
	}
	ft_printf("sorted!\n");
	return (1);
}

void	ft_sort3(t_list **stack_a)
{
	if (ft_min(*stack_a) == *(int *)(*stack_a)->content)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	(void)stack_b;
	size_a = ft_lstsize(*stack_a);
	if (size_a == 2)
		return (ft_sa(stack_a));
	if (size_a == 3)
		return (ft_sort3(stack_a));
	// else
	// 	return (ft_bigsort(stack_a, stack_b, size_a));
}
