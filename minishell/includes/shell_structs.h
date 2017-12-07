/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:51:59 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:21:21 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_STRUCTS_H
# define SHELL_STRUCTS_H

typedef struct			s_shcmd
{
	char				*cmd;
	char				**args;
}						t_shcmd;

typedef struct			s_env_item
{
	struct s_env_item	*next;
	struct s_env_item	*prev;
	char				**keyval;
	int					glob;
}						t_env_item;

#endif
