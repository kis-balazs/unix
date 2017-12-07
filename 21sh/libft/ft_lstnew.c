/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:57:42 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:57:43 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_llist		*ft_lstnew(void const *content, size_t content_size)
{
	t_llist	*ptr;
	void	*cnt;

	cnt = (void*)ft_memalloc(content_size + 1);
	cnt = ft_memcpy(cnt, content, content_size);
	ptr = (t_llist*)ft_memalloc(sizeof(t_llist));
	ptr->content_size = content_size;
	ptr->content = cnt;
	ptr->maillon_nb = 0;
	ptr->next = NULL;
	return (ptr);
}
