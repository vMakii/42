/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:07:10 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/10 15:43:29 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_op(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "pa", 2))
		ft_pa(a, b);
	if (!ft_strncmp(line, "pb", 2))
		ft_pb(b, a);
	if (!ft_strncmp(line, "sa", 2))
		ft_sa(a);
	if (!ft_strncmp(line, "sb", 2))
		ft_sb(b);
	if (!ft_strncmp(line, "ss", 2))
		ft_ss(a, b);
	if (!ft_strncmp(line, "ra", 2))
		ft_ra(a);
	if (!ft_strncmp(line, "rb", 2))
		ft_rb(b);
	if (!ft_strncmp(line, "rr", 2))
		ft_rr(a, b);
	if (!ft_strncmp(line, "rra", 4))
		ft_rra(a);
	if (!ft_strncmp(line, "rrb", 4))
		ft_rrb(b);
	if (!ft_strncmp(line, "rrr", 4))
		ft_rrr(a, b);
	return (get_next_line(0));
}
