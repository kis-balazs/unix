/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:46:05 by bkis              #+#    #+#             */
/*   Updated: 2017/01/10 18:23:38 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_wc(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	if (s[0] != c)
		word++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			word++;
		i++;
	}
	return (word);
}

static inline size_t	ft_lc(char const *s, char c, int i)
{
	size_t	lc;

	lc = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		lc++;
	}
	return (lc);
}

char					**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || (str = (char **)malloc(sizeof(char *) * ft_wc(s, c) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			if ((str[j] = ft_strnew(ft_lc(s, c, i) + 1)) == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				str[j][k++] = s[i++];
			str[j++][k] = '\0';
		}
	}
	str[j] = NULL;
	return (str);
}
