/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lexer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:45:52 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:45:53 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int		ctrl_tab2(int count, char *line)
{
	count++;
	if (line[count] == '-')
		return (count + 1);
	while (ft_isdigit(line[count]))
		count++;
	return (count);
}
