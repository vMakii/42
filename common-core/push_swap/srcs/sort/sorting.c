/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/11 14:07:49 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getmax(t_list *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	ft_getid(t_list *stack)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	head = stack;
	while (head)
	{
		i = 1;
		tmp = stack;
		while (tmp)
		{
			if (tmp->value < head->value)
				i++;
			tmp = tmp->next;
		}
		head->index = i;
		head = head->next;
	}
}

int	ft_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort3(t_list **stack)
{
	int	max;

	max = ft_getmax(*stack);
	if (ft_is_sorted(*stack))
		return ;
	if ((*stack)->index == max)
		ft_ra(stack);
	else if ((*stack)->next->index == max)
		ft_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack);
}

void	ft_sort5(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) == 3)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
			ft_pb(stack_b, stack_a);
		else
			ft_ra(stack_a);
	}
	if (ft_is_sorted(*stack_b))
		ft_sb(stack_b);
	ft_sort3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
