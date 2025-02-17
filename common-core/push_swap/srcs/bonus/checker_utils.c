/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:07:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/17 10:59:06 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_op(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "pa", 2))
		ft_pa(a, b, 1);
	else if (!ft_strncmp(line, "pb", 2))
		ft_pb(b, a, 1);
	else if (!ft_strncmp(line, "sa", 2))
		ft_sa(a, 1);
	else if (!ft_strncmp(line, "sb", 2))
		ft_sb(b, 1);
	else if (!ft_strncmp(line, "ss", 2))
		ft_ss(a, b, 1);
	else if (!ft_strncmp(line, "ra", 2))
		ft_ra(a, 1);
	else if (!ft_strncmp(line, "rb", 2))
		ft_rb(b, 1);
	else if (!ft_strncmp(line, "rr\n", 3))
		ft_rr(a, b, 1);
	else if (!ft_strncmp(line, "rra", 3))
		ft_rra(a, 1);
	else if (!ft_strncmp(line, "rrb", 3))
		ft_rrb(b, 1);
	else if (!ft_strncmp(line, "rrr", 3))
		ft_rrr(a, b, 1);
	return (get_next_line(0));
}
