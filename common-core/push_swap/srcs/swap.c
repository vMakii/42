/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:40:00 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/28 15:05:06 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !stack->next)
		return ;
	first = stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack = second;
}

// void	sa(t_stack **stack)
// {
// }
//
// void	sb(t_stack **stack)
// {
// }
//
// void	ss(t_stack **stack_a, t_stack **stack_b)
// {
// }
