/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:28 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/17 14:50:23 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_min(t_list *stack)
{
	int	min;
	int	value;

	min = *(int *)(stack)->content;
	while (stack)
	{
		value = *(int *)(stack)->content;
		if (value && value < min)
			min = value;
		stack = stack->next;
	}
	return (min);
}

int	ft_max(t_list *stack)
{
	int	max;
	int	value;

	max = *(int *)(stack)->content;
	while (stack)
	{
		value = *(int *)(stack)->content;
		if (value && value > max)
			max = value;
		stack = stack->next;
	}
	return (max);
}
