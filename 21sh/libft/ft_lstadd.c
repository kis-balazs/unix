/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:57:07 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:57:08 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void		ft_lstadd(t_llist **alst, t_llist *n)
{
	t_llist *ptr;

	ptr = *alst;
	if (ptr == NULL)
		*alst = n;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = n;
		ptr->next->maillon_nb = ptr->maillon_nb + 1;
	}
}
