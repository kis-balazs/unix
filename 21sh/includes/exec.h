/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:18:54 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:11:11 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "ast.h"
# define NB_TOKEN 6

typedef enum			e_code
{
	NONE,
	CD_FILES,
	CD_ARG,
	CD_CMD,
}						t_code;

typedef struct			s_exec
{
	t_token				token;
	int					(*f)(t_node *, int *);
}						t_exec;

typedef struct			s_pipe
{
	int					count;
	int					last;
	pid_t				*list;
}						t_pipe;

typedef	struct			s_list_fd
{
	int					fd[4];
	int					pcr;
}						t_list_fd;

char					**get_in_env(t_llist *env, const char *str);
int						find_command(char **cmd);

t_code					ctrl_arg(char **cmd, int *pos);

int						set_varible(t_node *ast, int *status);
int						pipe_function(t_node *ast, int *status);
int						logique_fonction(t_node *ast, int *status);
int						redirection_fonction(t_node *ast, int *status);
int						open_files(t_node *ast, int *status);
int						exec_fct(t_node *ast, int *status);
int						open_fd(t_node *ast, int *status);

pid_t					exec_right_pipe(t_pipe *pipe, t_node *right, int fd[2]);
pid_t					exec_left_pipe(t_pipe *pipe, t_node *left, int fd[2]);
void					new_pid(t_pipe *pipe, pid_t pid);
pid_t					verif_pid(t_pipe *pipe);
char					*create_var_env(char *sigle, char *var);
void					ft_get_pwd(void);
void					ft_cd(char **cmd, int index);
void					ft_setenv(char *name, char *value);
void					history(char **cmd);
void					ft_export(char *arg);
void					ft_unsetenv(char **name);
void					ft_echo(char **cmd);
void					fnc_exit();
void					print_env(void);
void					treat_redirection(t_node *ast, int fd[3], int *status);
void					reacast_fd(char *token, char *after, t_list_fd *list);

#endif
