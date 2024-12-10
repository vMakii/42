/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:19:08 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/10 11:59:45 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

// op
void				ft_sa(t_stack **stack);
void				ft_sb(t_stack **stack);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_b, t_stack **stack_a);
void				ft_ra(t_stack **stack);
void				ft_rb(t_stack **stack);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);
void				ft_rra(t_stack **stack);
void				ft_rrb(t_stack **stack);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

// sorting
int					ft_is_sorted(t_list **stack);
#endif
