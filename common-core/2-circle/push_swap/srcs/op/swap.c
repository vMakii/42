/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:40:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/14 10:37:13 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_sa(t_list **stack, int n)
{
	ft_swap(stack);
	if (n == 0)
		ft_printf("sa\n");
}

void	ft_sb(t_list **stack, int n)
{
	ft_swap(stack);
	if (n == 0)
		ft_printf("sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b, int n)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (n == 0)
		ft_printf("ss\n");
}
