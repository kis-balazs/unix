/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:04:29 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 14:04:30 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int		cmp(char c, int *t)
{
	while (*t)
	{
		if (*t == c)
			return (*t - c);
		t++;
	}
	return (-1);
}

static char		*my_strrchr(const char *s, int *t)
{
	size_t		i;

	i = 0;
	while ((cmp(s[i], t) == -1) && s[i])
		i++;
	if ((cmp(s[i], t) == 0))
		return ((char *)&s[i]);
	return (NULL);
}

static int		ft_stspchr(char *s, int *t)
{
	int			i;
	int			j;

	i = 0;
	while ((cmp(s[i], t) == 0) && s[i])
		i++;
	while (s[i])
	{
		while ((cmp(s[i], t) == -1) && s[i])
			i++;
		if ((cmp(s[i], t) == 0))
		{
			while ((cmp(s[i], t) == 0))
				i++;
			return (i - 1);
		}
	}
	return (i);
}

static int		find_occur(const char *s, int *t)
{
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	while ((cmp(s[i], t) == 0) && s[i])
		i++;
	while (s[i])
	{
		while ((cmp(s[i], t) == -1) && s[i])
			i++;
		if ((cmp(s[i], t) == 0) || !s[i])
		{
			while ((cmp(s[i], t) == 0))
				i++;
			ret++;
		}
	}
	return (ret);
}

int				ft_strsplit(char ***dst, char const *s, int *t)
{
	int			pos;
	int			i;
	int			len;

	if (!s)
		return (0);
	if ((len = find_occur(s, t)) == 0)
		return (-1);
	*dst = malloc(sizeof(char*) * (len + 1));
	i = 0;
	while (i < len)
	{
		while ((cmp(*s, t) == 0))
			s++;
		dst[0][i] = ft_strndup((char*)s, 0, ft_stspchr((char*)s, t));
		s = my_strrchr(s, t);
		i++;
	}
	dst[0][i] = NULL;
	return (len);
}
