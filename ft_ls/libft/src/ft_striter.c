/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:56:35 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:56:36 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int		index;
	char	*c;

	index = 0;
	while (s[index])
	{
		c = (s + index);
		(f)(c);
		index++;
	}
}
