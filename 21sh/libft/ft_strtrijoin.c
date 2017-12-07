/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrijoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:04:58 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:04:59 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char		*ft_strtrijoin(const char *s1, const char *s2, const char *s3)
{
	char *tmp;
	char *ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	ret = ft_strjoin(tmp, s3);
	free(tmp);
	return (ret);
}
