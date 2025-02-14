/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:30:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/14 10:32:08 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	ft_pa(t_list **stack_a, t_list **stack_b, int n)
{
	ft_push(stack_a, stack_b);
	if (n == 0)
		ft_printf("pa\n");
}

void	ft_pb(t_list **stack_b, t_list **stack_a, int n)
{
	ft_push(stack_b, stack_a);
	if (n == 0)
		ft_printf("pb\n");
}
