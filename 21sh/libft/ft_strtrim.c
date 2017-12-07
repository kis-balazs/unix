/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:05:15 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:05:16 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	int			j;
	int			len;
	int			size;
	char		*tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	size = len - i;
	if (size < 0)
		size = 0;
	tmp = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (NULL);
	while (i <= len)
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (tmp);
}
