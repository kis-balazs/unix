/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:54:00 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:54:01 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	isascii(char c)
{
	return ((c >= '!' && c <= '~'));
}

void				ft_puthex(unsigned char num)
{
	if (num >= 16)
	{
		ft_puthex(num / 16);
		ft_puthex(num % 16);
	}
	if (num < 10)
		ft_putchar(num + '0');
	else if (num < 16)
		ft_putchar(num + 87);
}

char				*print_line_ascii(char *addr, int b)
{
	int c;

	c = 0;
	if (b != 16)
	{
		while (b % 16)
		{
			c++;
			b++;
			ft_putstr("  ");
			if (!(b % 2))
				ft_putchar(' ');
		}
		b = 16 - c;
	}
	while (b > 0 && addr)
	{
		ft_putchar(isascii(*addr) ? *addr : '.');
		addr++;
		b--;
	}
	ft_putchar('\n');
	return (addr);
}

void				ft_pmem(const void *addr, size_t t)
{
	size_t			i;
	unsigned char	*p;
	char			*c;

	i = 0;
	if (!addr)
		return ;
	p = (unsigned char *)addr;
	c = (char*)p;
	while (i < t)
	{
		if (!*p || *p < 0x10)
			ft_putchar('0');
		ft_puthex(*p);
		p++;
		i++;
		if (!(i % 2))
			ft_putchar(' ');
		if (!(i % 16) || i >= t)
			c = print_line_ascii(c, i < t ? 16 : i);
	}
}
