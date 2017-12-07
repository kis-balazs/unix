/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtstrwchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:56:03 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:56:03 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_lenghstrwchar(const wchar_t *wc)
{
	int count;

	count = 0;
	while (*wc)
		count += ft_lenghtwchar(*wc++);
	return (count);
}
