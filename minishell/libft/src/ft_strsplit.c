/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:00:56 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 17:00:56 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	how_strings(char const *s, char *c)
{
	int	i;
	int	co;

	i = 0;
	co = 0;
	while (s[i])
	{
		while (ft_strchr(c, s[i++]))
			if (!s[i])
				return (co);
		while (ft_strchr(c, s[i]) && s[i])
			i++;
		co++;
	}
	return (co);
}

char				**ft_strsplit(char const *s, char *c)
{
	char	**ret;
	int		i;
	int		len;
	int		i_ptr;

	i = 0;
	i_ptr = 0;
	ret = malloc((sizeof(char *) * how_strings(s, c)) + 1);
	if (!s || !ret)
		return (NULL);
	while (s[i])
	{
		len = 0;
		while (s[i] && ft_strchr(c, s[i]))
			i++;
		while (s[i + len] && !ft_strchr(c, s[i + len]))
			len++;
		if (len)
			if (!(ret[i_ptr++] = ft_strsub(s, i, len)))
				return (NULL);
		i = i + len;
	}
	ret[i_ptr] = NULL;
	return (ret);
}
