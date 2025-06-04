/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:01:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/06/04 12:27:47 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>

typedef enum tokens
{
	IN,      // 0
	HEREDOC, // 1
	OUT,     // 2
	APPEND,  // 3
	PIPE,    // 4
	CMD,     // 5
	BUILTIN, // 6
	ARG,     // 7
	SPC,     // 8
}					t_tokens;

typedef struct s_cmd
{
	char			*str;
	t_tokens		type;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_data
{
	char			*prompt;
	t_cmd			*cmd;
	char			**env;
	int				exit;
	int				exit_status;
}					t_data;

void				ft_free(t_data *data);
// builtin
int					ft_echo(char **args);
int					ft_env(t_data *data);
void				ft_exit(t_data *data);
int					ft_export(char **args, t_data *data);
int					ft_pwd(void);
void				ft_unset(t_data *data);

// env
char				**ft_getenv(char **envp);
void				ft_update_shlvl(char **env);

// parsing
char				*ft_expand(t_data *data, char *str);
bool				ft_parse(t_data *data);
void				ft_cutword(char *str, int *i, int *start, int *end);
char				*ft_optimize(char *str);
char				*ft_strtrim_quote(char *str);
t_cmd				*ft_getcmd(t_data *data, t_tokens type);
bool				ft_tokenize(t_data *data, int start, int end);

// utils
void				ft_free(t_data *data);
t_cmd				*ft_lstnew(char *str, t_tokens type);
void				ft_lstadd_back(t_cmd **lst, t_cmd *new);
int					ft_lstsize(t_cmd *lst);
void				ft_lstclear(t_cmd **lst);
void				ft_lstprint(t_cmd *lst);
char				**dup_env(char **envp);
void				sort_arr(char **envp, int len);
int					env_size(char **envp);

#endif
