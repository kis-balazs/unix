/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:01:16 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:01:16 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*strconct(char *s1, char *s2, const char *obj)
{
	char *tmp;
	char *ret;

	tmp = ft_strcatdup(s1, obj);
	ret = ft_strcatdup(tmp, s2);
	return (ret);
}
