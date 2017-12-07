/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:56:51 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:56:52 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char const *src)
{
	char *origin;
	char *tmp;

	origin = dest;
	tmp = (char *)src;
	while (*tmp)
	{
		*origin = *tmp;
		origin++;
		tmp++;
	}
	*origin = *tmp;
	return (dest);
}
