/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:51:32 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/14 10:35:35 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_list **stack, int n)
{
	ft_reverse_rotate(stack);
	if (n == 0)
		ft_printf("rra\n");
}

void	ft_rrb(t_list **stack, int n)
{
	ft_reverse_rotate(stack);
	if (n == 0)
		ft_printf("rrb\n");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b, int n)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (n == 0)
		ft_printf("rrr\n");
}
