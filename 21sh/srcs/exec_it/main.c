/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:25:32 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:08:41 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "termcaps.h"

int					find_varibale(char *str, char c)
{
	int				count;

	count = 0;
	while (str[count])
	{
		if (str[count] == c)
			return (1);
		count++;
	}
	return (-1);
}

void				end_memory(void)
{
	if (g_memory.line)
		free(g_memory.line);
	if (g_memory.key_ctrl)
		free(g_memory.key_ctrl);
	if (g_memory.variable != NULL)
		ft_lstdel(&(g_memory.variable), ft_bzero);
	if (g_memory.line_mode != NULL)
		free(g_memory.line_mode);
}

void				init(void)
{
	sig_init();
	ft_bzero(&g_memory, sizeof(t_memory));
	g_env = build_env();
	tc_init(&g_memory);
	g_memory.mode = SHELL;
	get_histfile_path();
	if (is_dir(search_env(g_env, "HISTORY=")) == FILES)
		hst_retrieve(&g_memory);
	ft_putstr_fd(PROMPT, STDERR_FILENO);
}

int					main(void)
{
	t_mode			mode;

	init();
	mode = SHELL;
	while (42)
	{
		termcaps(&g_memory);
		tc_restore_default(&g_memory);
		g_memory.mode = lexer_parser(&g_memory);
		tc_unset_canonical(&g_memory);
		if (g_memory.mode == SHELL)
		{
			if (g_memory.inp.multi_line)
				chreplace(g_memory.inp.cmd, '\n', ' ');
			hst_push(&g_memory, NULL);
			g_memory.line = NULL;
			g_memory.line_lenght = 0;
		}
		cbuf_reset(&g_memory);
	}
	end_memory();
	return (0);
}
