/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:01:29 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/16 17:13:56 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>

# define POSITIVE_MAX 9223372036854775807ULL
# define NEGATIVE_MAX 9223372036854775808ULL
# define INPUT_SIZE 1024
# define MAX_PIPES 1000
# define MAX_PROCESSES 1025

# define BASE_CASE 0
# define SIGINT_BASE_CASE 1
# define IN_HEREDOC 2
# define SIGINT_HEREDOC 3
# define CHILD 4
# define IGNORE 5

# define PROMPT_COLOR "\001\033[0;35m\002"
# define PROMPT_RESET "\001\033[0m\002"
# define PROMPT_TEXT "minishell> "

extern volatile sig_atomic_t	g_sig;

//  -- Enum -- //
typedef enum tokens
{
	IN,
	HEREDOC,
	OUT,
	APPEND,
	PIPE,
	CMD,
	BUILTIN,
	ARG,
	SPC,
}								t_tokens;

//  -- Structs -- //
typedef struct s_expand
{
	char						*exp;
	int							i;
	int							j;
	int							len;
	int							in_sgl;
	int							in_dbl;
}								t_expand;

typedef struct s_cmd
{
	char						*str;
	t_tokens					type;
	struct s_cmd				*next;
	struct s_cmd				*prev;
}								t_cmd;

typedef struct s_exec
{
	int							in;
	int							out;
	int							saved_stdin;
	int							saved_stdout;
	char						*cmd;
	char						*argv;
}								t_exec;

typedef struct s_pipeline_state
{
	int							nb_pipes;
	int							pipefd[2];
	pid_t						pid[MAX_PROCESSES];
	int							i;
	int							old_fd;
	int							sig;
}								t_pipeline_state;

typedef struct s_data
{
	char						*prompt;
	t_cmd						*cmd;
	char						**env;
	int							heredoc_i;
	int							heredoc_fd;
	int							exit;
	int							exit_status;
}								t_data;

//  -- Builtin -- //
int								ft_cd(char **args, t_data *data);
int								ft_echo(char **args);
int								ft_env(t_data *data);
void							ft_exit(t_data *data);
int								export(char ***env, char *str);
int								ft_export(char **args, t_data *data);
int								var_index(char **env, const char *var);
int								ft_pwd(void);
int								ft_unset(t_data *data);

//  -- Exec -- //
char							*get_command_path(char *cmd, t_data *data);
int								ft_getnb_pipe(t_data *data);
void							ft_exec_builtin(t_data *data, t_cmd *cmd,
									char **argv);
void							ft_exec(t_data *data);
void							ft_exec_pipeline(t_data *data, t_cmd *cmd,
									t_exec *exec);
void							ft_exec_cmd(t_data *data, t_cmd *cmd);
char							**ft_get_argv(t_cmd *cmd);
void							ft_handle_redir(t_data *data, t_exec *exec,
									t_cmd *cmd);
void							ft_next_segment(t_cmd **cmd);
bool							ft_prepare_heredocs(t_data *data);
char							*ft_readline(void);
void							init_pipeline_state(t_data *data,
									t_pipeline_state *state);
void							close_pipedfds(int pipefd1, int pipefd2);
bool							ft_pipe(t_cmd *cmd, int *pipefd);
void							init_pipeline_state(t_data *data,
									t_pipeline_state *state);
void							ft_next_segment(t_cmd **cmd);
void							ft_child_process(t_pipeline_state *state,
									t_cmd *cmd, t_exec *exec, t_data *data);
void							ft_wait_for_child(t_pipeline_state *state,
									t_data *data);
void							ft_parent_process(t_pipeline_state *state,
									t_cmd **cmd);

// -- Parsing -- //
bool							ft_check_redir_utils(const char *str, int i);
char							*ft_expand(t_data *data, char *str);
bool							ft_parse(t_data *data);
void							ft_cutword(char *str, int *i, int *start,
									int *end);
char							*ft_optimize(char *str);
char							*ft_strtrim_quote(char *str);
t_cmd							*ft_getcmd(t_data *data, t_tokens type);
bool							ft_tokenize(t_data *data, int start, int end);

// -- Signals -- //
void							ft_set_signal(t_data *data, int flag);
void							ft_setup_child_signals(void);
void							ft_setup_heredoc_signals(void);
void							ft_setup_signals(void);
void							ft_ignore_signals(void);

//  -- Utils -- //
void							update_env_var(t_data *data,
									const char *var_name, const char *value);
int								get_var_len(const char *str);
char							*get_env_value(char **env, const char *name);
char							**ft_getenv(char **envp);
void							ft_free(t_data *data, int end);
bool							is_tty(void);
void							ft_print_error(char *msg);
char							**dup_env(char **envp);
void							sort_arr(char **envp, int len);
int								env_size(char **envp);
t_cmd							*ft_lstnew(char *str, t_tokens type);
void							ft_lstadd_back(t_cmd **lst, t_cmd *new);
int								ft_lstsize(t_cmd *lst);
void							ft_lstclear(t_cmd **lst);
void							ft_lstprint(t_cmd *lst);
char							*ft_random_filename(char *hd, size_t i);
bool							_is_dir(char *cmd, t_data *data);
char							*_access_check(char *cmd, t_data *data);
char							*_random_file_name(char *dst, size_t len);
bool							heredoc_read(t_data *data, int fd,
									char *delimiter);
int								_heredoc_util(t_data *d, int fd,
									const char *name, char *eof);
int								ft_expand_len(t_data *data, const char *str);
void							_free_utils(char **argv, t_data *data, int end);

#endif
