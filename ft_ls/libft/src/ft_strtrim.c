/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:58:37 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:58:38 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		len;
	int		cd;
	int		cf;

	cd = 0;
	cf = 0;
	len = (ft_strlen(s) - 1);
	while (s[cd] == ' ' || s[cd] == '\n' || s[cd] == '\t')
		cd++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		len--;
		cf++;
	}
	if ((cf + cd) != 0 && cf != (int)ft_strlen(s))
	{
		if ((ret = ft_strnew(ft_strlen(s) - (cd + cf))))
			ft_strncpy(ret, (s + cd), (ft_strlen(s) - (cd + cf)));
	}
	else if (cf == (int)ft_strlen(s))
		return ("");
	else
		ret = ft_strdup(s);
	return (ret);
}
