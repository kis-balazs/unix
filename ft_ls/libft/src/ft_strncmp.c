/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:57:28 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:57:29 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	if (ft_strlen(s1) >= n && ft_strlen(s2) >= n)
		return (ft_memcmp(s1, s2, n));
	else
	{
		if (ft_strlen(s1) > ft_strlen(s2))
			return (ft_memcmp(s1, s2, ft_strlen(s2) + 1));
		else
			return (ft_memcmp(s1, s2, ft_strlen(s1) + 1));
	}
}
