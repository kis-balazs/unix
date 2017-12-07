/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtunint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:56:17 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:56:18 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int			ft_lenghtunint(unsigned int nb)
{
	size_t	ret;

	ret = 1;
	if (nb == UINT_MAX)
		return (10);
	while ((nb /= 10) > 0)
		ret++;
	return (ret);
}
