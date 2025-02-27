/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:19:08 by mivogel           #+#    #+#             */
/*   Updated: 2025/02/27 14:58:50 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include "../libft/includes/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_list;

// op
void				ft_sa(t_list **stack, int n);
void				ft_sb(t_list **stack, int n);
void				ft_ss(t_list **stack_a, t_list **stack_b, int n);
void				ft_pa(t_list **stack_a, t_list **stack_b, int n);
void				ft_pb(t_list **stack_b, t_list **stack_a, int n);
void				ft_ra(t_list **stack, int n);
void				ft_rb(t_list **stack, int n);
void				ft_rr(t_list **stack_a, t_list **stack_b, int n);
void				ft_rra(t_list **stack, int n);
void				ft_rrb(t_list **stack, int n);
void				ft_rrr(t_list **stack_a, t_list **stack_b, int n);
// sort
void				ft_pushb(t_list **stack_a, t_list **stack_b, int size);
void				ft_sort(t_list **stack_a, t_list **stack_b, int size);
void				ft_move(t_list **stack_a, t_list **stack_b, int cost_a,
						int cost_b);
int					ft_getmax(t_list *stack);
void				ft_getid(t_list *stack);
int					ft_is_sorted(t_list *stack);
void				ft_sort3(t_list **stack);
void				ft_sort5(t_list **stack_a, t_list **stack_b, int size);
// utils
int					ft_check(int ac, char **av, t_list **a, t_list **b);
void				ft_lstclear(t_list **lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(int value);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_init(char **av, int n);
int					ft_abs(int n);
void				ft_target(t_list **stack_a, t_list **stack_b);
void				ft_cost(t_list **stack_b, int size_a);
// bonus
char				*ft_op(t_list **a, t_list **b, char *line);

#endif
