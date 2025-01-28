/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:56:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/28 15:40:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	getmax(t_list *stack)
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
		i = 0;
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

	max = getmax(*stack);
	if (ft_is_sorted(*stack))
		return ;
	if ((*stack)->index == max)
		ft_ra(stack);
	else if ((*stack)->next->index == max)
		ft_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack);
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	max;

	ft_pushb(stack_a, stack_b, size);
	ft_sort3(stack_a);
	while (*stack_b)
	{
		max = getmax(*stack_a);
		if ((*stack_b)->index > max && (*stack_a)->index == max - 1)
			ft_pa(stack_a, stack_b);
		else if ((*stack_b)->index > (*stack_a)->index)
			ft_ra(stack_a);
		else
			ft_pa(stack_a, stack_b);
	}
	while ((*stack_a)->index != 0)
		ft_rra(stack_a);
}
