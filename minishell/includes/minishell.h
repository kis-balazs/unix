/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:51:52 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:21:16 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stddef.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"

# include "shell_structs.h"

# define HASHT_SIZE 40

t_env_item		*env_new_item(char **keyval, char *keyval_in_one, int g);
int				menv(t_env_item **env, char **args);
int				env_populate(t_env_item **env, char **environ);
int				env_fake_sort(t_list *t, t_list *n);
int				msetenv(t_env_item **env, char **keyval, char *pair, int g);
int				setenv_check(char *pair);
int				munsetenv(t_env_item **env, char *key);
char			**get_env_keys(t_env_item **env);
char			*mgetenv(t_env_item *env, char *key);
void			env_print_node(t_list *m);
void			env_print(t_env_item *env);
void			env_free(t_env_item **env);
void			env_del_one(void *t);
char			**env_to_table(t_env_item *env);
void			myexit(t_env_item **env, char *nu, char *msg);
void			env_item_del(t_env_item **env, int hash);
void			bi_echo(char **args);
int				bi_cd(char **av, t_env_item *env);
int				try_dir(char *dir, char *arg);
int				shparse(char *line, t_shcmd *cmd, t_env_item *env);
void			shell_loop(t_env_item **env);
int				forkexec(char *cmd, char **av, t_env_item **env);
char			*in_path(char *cmd, char *path);
char			*cin_c2c(char *c1, char **c2);
int				exec_cmd(t_shcmd *cmd, t_env_item **env);
int				builtins(t_shcmd *cmd, t_env_item **env);
void			sp_prompt(t_env_item *env, int ret);
#endif
