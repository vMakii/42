/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:19:08 by mivogel           #+#    #+#             */
/*   Updated: 2024/12/18 14:42:17 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

typedef struct s_list
{
	int				nb;
	int				index;
	struct s_list	*next;
}					t_list;

// op
void				ft_sa(t_list **stack);
void				ft_sb(t_list **stack);
void				ft_ss(t_list **stack_a, t_list **stack_b);
void				ft_pa(t_list **stack_a, t_list **stack_b);
void				ft_pb(t_list **stack_b, t_list **stack_a);
void				ft_ra(t_list **stack);
void				ft_rb(t_list **stack);
void				ft_rr(t_list **stack_a, t_list **stack_b);
void				ft_rra(t_list **stack);
void				ft_rrb(t_list **stack);
void				ft_rrr(t_list **stack_a, t_list **stack_b);
// checks
void				ft_init(t_list **stack, int ac, char **av);
int					ft_check_args(int ac, char **av);
// sorting
int					ft_is_sorted(t_list **stack);
void				ft_sort3(t_list **stack);
void				ft_sort(t_list **stack_a, t_list **stack_b);
// utils
void				ft_lstclear(t_list **lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(int value);
int					ft_max(t_list *stack);
void				ft_lstadd_back(t_list **lst, t_list *new);

#endif
