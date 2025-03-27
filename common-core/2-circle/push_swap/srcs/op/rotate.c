/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:48:16 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/14 10:36:37 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_ra(t_list **stack, int n)
{
	ft_rotate(stack);
	if (n == 0)
		ft_printf("ra\n");
}

void	ft_rb(t_list **stack, int n)
{
	ft_rotate(stack);
	if (n == 0)
		ft_printf("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b, int n)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (n == 0)
		ft_printf("rr\n");
}
