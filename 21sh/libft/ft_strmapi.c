/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:02:49 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:02:49 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_res;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((str_res = ft_strdup((char*)s)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str_res[i] = f(i, s[i]);
		i++;
	}
	return (str_res);
}
