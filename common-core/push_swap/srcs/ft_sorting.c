/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:29 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/19 11:52:38 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_id(t_list *stack)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	head = stack;
	while (head)
	{
		i = 0;
		tmp = stack;
		while (tmp)
		{
			if (tmp->nb < head->nb)
				i++;
			tmp = tmp->next;
		}
		head->index = i;
		// ft_printf("id : %d\n", head->index);
		head = head->next;
	}
}

int	ft_is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->nb > head->next->nb)
		{
			// ft_printf("not sorted!\n");
			return (0);
		}
		head = head->next;
	}
	// ft_printf("sorted!\n");
	return (1);
}

void	ft_sort3(t_list **stack)
{
	int	max;

	max = ft_max(*stack);
	if (ft_is_sorted(stack))
		return ;
	if ((*stack)->index == max)
		ft_ra(stack);
	else if ((*stack)->next->index == max)
		ft_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	ft_id(*stack_a);
	if (size_a == 2)
		return (ft_sa(stack_a));
	if (size_a == 3)
		return (ft_sort3(stack_a));
	else
		return (ft_bigsort(stack_a, stack_b, size_a));
}
