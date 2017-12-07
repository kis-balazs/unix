/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:19:06 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:11:24 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>
# define NB_BUILT 8
# define RBUF_SIZE	8
# define PROMPT	"$ "
# define PROMPT_SIZE 2
# define SUCCESS 0
# define SWITCH_MODE 262144
# define SHELL_CODE 262145
# define QUOTE_CODE 262146
# define D_QUOTE_CODE 262147
# define BACKQUOTE_CODE 262148
# define HEREDOC_CODE 262149
# define BCKSLASH_CODE 262150
# define MACREALLOC(ret, name, size) (ret = ft_realloc(name, size));

typedef	enum e_mode				t_mode;
typedef struct s_memory			t_memory;
typedef struct s_cursor			t_cursor;
typedef struct s_input			t_input;
typedef struct s_clipboard		t_clipboard;
typedef struct s_history		t_history;
typedef struct s_history_list	t_hlst;

t_memory		g_memory;
t_llist			*g_env;

enum				e_mode
{
	SHELL,
	HEREDOC,
	QUOTE,
	D_QUOTE,
	BACKQUOTE,
	BCKSLASH,
	ERROR,
};

enum				e_sh_state
{
	IDLE,
	HGL,
	ENCL,
	HERED
};

struct				s_input
{
	char			rbuf[RBUF_SIZE + 1];
	char			missing;
	char			*cbuf;
	char			*cmd;
	size_t			cbuflen;
	size_t			cmdlen;
	size_t			maxlen;
	bool			multi_line;
	bool			ready;
};

struct				s_cursor
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	x_max;
	unsigned int	y_max;
	unsigned int	win_x;
	unsigned int	win_y;
	unsigned int	i;
	unsigned int	s_i;
};

struct				s_clipboard
{
	char			*buf;
	size_t			len;
};

struct				s_history_list
{
	t_hlst			*prev;
	t_hlst			*next;
	char			*cmd;
	char			*line;
	size_t			cmdlen;
};

struct				s_history
{
	t_hlst			*head;
	t_hlst			*tmphead;
	t_hlst			*end;
	t_hlst			*current;
	char			*last_cmd;
	size_t			last_cmdlen;
	bool			browsing;
};

struct				s_memory
{
	int				fd_history;
	int				code_history;
	char			*line;
	int				env_lenght;
	char			*key_ctrl;
	int				heredoc_sw;
	t_llist			*variable;
	int				var_lenght;
	char			*line_mode;
	char			*line_mode_after;
	t_mode			mode;
	int				launch;
	int				line_lenght;
	struct termios	term;
	struct termios	term_d;
	enum e_sh_state	state;
	t_input			inp;
	t_cursor		curs;
	t_clipboard		cb;
	t_history		hst;
	int				signo;
};

void				termcaps(t_memory *sh);
void				sh_abort(char *msg);

void				sig_handler(t_memory *sh);
void				sig_init(void);

t_llist				*build_env(void);
int					count_env(t_llist *env);
char				*search_env(t_llist *env, const char *value);
char				**copy_env(void);
void				clear_env(t_llist **env, const char *value, int *lenght);
void				set_env(t_llist **env, t_llist *new);

t_mode				lexer_parser(t_memory *memory);
char				**init_option(char *opt, char **save, int index);
int					operator_filters(char *line);
int					ctrl_var(char *line);
int					my_ctrl(int test);
int					is_bulltin(char *cmd);
int					operator_ctrl(int test);
int					find_str(char *line);
int					ctrl_mode(char *line, t_memory *memory);
int					ctrl_quot(int first, int second);
bool				from_deep_space(char *str, size_t len);

t_llist				*my_setenv();
char				**my_env(t_llist *env);
int					unenv(char *unset, t_llist *env);
int					env_collapse(t_llist *env, const char *value);
void				replace_env(t_llist **list, char *sigle, char *new,
								int *lenght);

void				init_memory(void);
void				end_memory(void);
void				get_histfile_path(void);
char				**convert_history();

void				*ft_realloc(void *mem, size_t size);
void				free_d(char **dtab, int lenght);
char				**find_path(int *lenght);

char				*get_pwd(void);
int					reset_fd(int fd, char *new_fd);
int					find_varibale(char *str, char c);
void				free_mai(t_llist **env, t_llist *ptr, t_llist *sb,
								t_llist *s);

void				print_env(void);

#endif
