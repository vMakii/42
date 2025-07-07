/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:04:15 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/01 14:50:42 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lstnew(char *str, t_tokens type)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->str = str;
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

int	ft_lstsize(t_cmd *lst)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_cmd **lst)
{
	t_cmd	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
}

void	ft_lstprint(t_cmd *lst)
{
	while (lst)
	{
		printf("str: [\e[1;32m%s\e[0m]", lst->str);
		if (lst->type == IN)
			printf("\ttype: [\e[1;34mIN\e[0m]\n");
		else if (lst->type == HEREDOC)
			printf("\ttype: [\e[1;34mHEREDOC\e[0m]\n");
		else if (lst->type == OUT)
			printf("\ttype: [\e[1;34mOUT\e[0m]\n");
		else if (lst->type == APPEND)
			printf("\ttype: [\e[1;34mAPPEND\e[0m]\n");
		else if (lst->type == PIPE)
			printf("\ttype: [\e[1;34mPIPE\e[0m]\n");
		else if (lst->type == CMD)
			printf("\ttype: [\e[1;34mCMD\e[0m]\n");
		else if (lst->type == BUILTIN)
			printf("\ttype: [\e[1;34mBUILTIN\e[0m]\n");
		else if (lst->type == ARG)
			printf("\ttype: [\e[1;34mARG\e[0m]\n");
		else if (lst->type == SPC)
			printf("\ttype: [\e[1;34mSPC\e[0m]\n");
		lst = lst->next;
	}
}
