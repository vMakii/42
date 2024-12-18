/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:48:16 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/18 14:57:58 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_ra(t_list **stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

void	ft_rb(t_list **stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
