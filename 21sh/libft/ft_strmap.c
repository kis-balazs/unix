/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:02:43 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:02:44 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_res;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((str_res = ft_strdup((char*)s)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_res[i] = f(s[i]);
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}
