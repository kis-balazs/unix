/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:57:13 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:57:14 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_lstdel(t_llist **alst, void (*del)(void *, size_t))
{
	if (*alst && del)
	{
		ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
	}
}
