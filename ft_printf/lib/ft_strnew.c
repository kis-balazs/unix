/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:23:44 by bkis              #+#    #+#             */
/*   Updated: 2017/07/05 16:23:45 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*text;

	text = (char *)malloc((size + 1) * sizeof(char));
	if (!text)
		return (NULL);
	ft_memset(text, '\0', size + 1);
	return (text);
}
