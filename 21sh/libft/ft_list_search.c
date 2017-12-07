/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:57:01 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:57:02 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_llist		*ft_list_search(t_llist *e, const char *str)
{
	while (((ft_strcmp(e->content, str)) && (e->next != NULL)))
		e = e->next;
	if (e->content == NULL)
		return (NULL);
	return (e->content);
}
