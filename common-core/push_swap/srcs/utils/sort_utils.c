/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:55:57 by mivogel           #+#    #+#             */
/*   Updated: 2025/01/29 16:09:47 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static void	get_pos(t_list **stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	get_target_pos(t_list **stack_a, int index, int target_pos)
{
	t_list	*tmp;
	int		target_id;

	tmp = *stack_a;
	target_id = INT_MAX;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < target_id)
		{
			target_id = tmp->index;
			target_pos = tmp->pos;
		}
		else if (tmp->index < target_id)
		{
			target_id = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

void	ft_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		target;

	target = 0;
	tmp = *stack_b;
	get_pos(stack_a);
	get_pos(stack_b);
	while (tmp)
	{
		target = get_target_pos(stack_a, tmp->index, target);
		tmp->target = target;
		tmp = tmp->next;
	}
}

void	ft_cost(t_list **stack_b, int size_a)
{
	t_list	*b;
	int		size_b;

	b = *stack_b;
	size_b = ft_lstsize(b);
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > size_b / 2)
			b->cost_b = (size_b - b->pos) * -1;
		b->cost_a = b->target;
		if (b->target > size_a / 2)
			b->cost_a = (size_b - b->target) * -1;
		b = b->next;
	}
}
