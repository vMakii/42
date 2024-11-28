/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:48:16 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/28 16:51:01 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

static void	ft_rotate(t_stack **stack)
{
}

void	ft_ra(t_stack **stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
