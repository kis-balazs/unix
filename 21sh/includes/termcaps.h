/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:19:10 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:11:30 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include <unistd.h>
# include <term.h>
# include <curses.h>
# include <dirent.h>
# include <signal.h>
# include "libft.h"
# include "shell.h"

typedef struct			s_autocompl
{
	t_llist				*match;
	int					lenght;
	int					occurance;
	int					max_word;
}						t_autocmp;

void					dbg_history(t_memory *sh);
void					write_history(t_memory *memory);

void					init_term(t_memory *sh);

void					tc_init(t_memory *sh);
void					tc_restore_default(t_memory *sh);
void					tc_set_blocking_read(t_memory *sh);
void					tc_set_timed_read(t_memory *sh);
void					tc_unset_canonical(t_memory *sh);
void					tc_write(const char *cap, ...);
void					tc_refresh(t_memory *sh);

void					cbuf_append(t_memory *sh, char inp);
void					cbuf_insert(t_memory *sh, char inp);
void					cbuf_print(t_memory *sh, bool delete);
void					cbuf_reset(t_memory *sh);
void					cbuf_check_size(t_memory *sh, size_t len);

void					evt_handler(t_memory *sh);
void					evt_printable(t_memory *sh);
void					evt_newline(t_memory *sh);
void					evt_backspace(t_memory *sh);
void					evt_del(t_memory *sh);
void					evt_tab(t_memory *sh);
void					evt_home(t_memory *sh);
void					evt_end(t_memory *sh);
void					evt_dpad_up(t_memory *sh);
void					evt_dpad_down(t_memory *sh);
void					evt_dpad_left(t_memory *sh);
void					evt_dpad_right(t_memory *sh);
void					evt_ctrl_d(t_memory *sh);
void					evt_ctrl_h(t_memory *sh);
void					evt_ctrl_p(t_memory *sh);
void					evt_ctrl_dpad_up(t_memory *sh);
void					evt_ctrl_dpad_down(t_memory *sh);
void					evt_ctrl_dpad_left(t_memory *sh);
void					evt_ctrl_dpad_right(t_memory *sh);

void					cb_copy_internal(t_memory *sh, bool cut);
void					cb_cut_internal(t_memory *sh, int start, size_t size,
										size_t total);
void					cb_paste_internal(t_memory *sh);
void					cb_paste_external(t_memory *sh);

void					highlight(t_memory *sh);
void					highlight_cleanup(t_memory *sh, bool cut, int start);

void					hst_push(t_memory *sh, char *line);
void					hst_tmp_push(t_memory *sh);
void					hst_retrieve(t_memory *sh);
void					hst_update_cbuf(t_memory *sh);
void					hst_browse_prev(t_memory *sh);
void					hst_browse_next(t_memory *sh);

int						autocompletion(t_memory *sh);
void					rsearch(char *str, char *trep, t_autocmp *autc);
void					remove_autc(t_autocmp *autocmp);
void					auto_push(char *str, t_memory *sh, int pos);
void					aff_auto(t_autocmp *autocmpl, t_memory *sh);

#endif
