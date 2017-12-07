/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:55:59 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:56:00 by bkis             ###   ########.fr       */
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
