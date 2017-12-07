/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:56:17 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:56:18 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int index;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index])
		index++;
	if (s1[index] == s2[index])
		index = 1;
	else
		index = 0;
	return (index);
}
