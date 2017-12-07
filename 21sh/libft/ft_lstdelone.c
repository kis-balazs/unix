/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:57:21 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:57:22 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_lstdelone(t_llist **alst, void (*del)(void*, size_t))
{
	if (*alst)
		(*del)((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)alst);
}
