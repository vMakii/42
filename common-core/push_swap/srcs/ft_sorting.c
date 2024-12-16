/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:29 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/16 15:27:16 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content < head->next->content)
		{
			ft_printf("not sorted!\n");
			return (0);
		}
		head = head->next;
	}
	ft_printf("sorted!\n");
	return (1);
}

// void	ft_simple_sort(t_list **stack_a, t_list **stack_b, int size_a)
// {
// 	return ;
// }

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if (size_a == 2)
		return (ft_sa(stack_a));
	if (size_a <= 5)
		return (ft_5sort(stack_a, stack_b, size_a));
	if (size_a <= 50)
		return (ft_50sort(stack_a, stack_b, size_a));
	else
		return (ft_bigsort(stack_a, stack_b, size_a));
}
