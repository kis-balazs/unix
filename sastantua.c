/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 14:10:37 by bkis              #+#    #+#             */
/*   Updated: 2016/08/07 17:32:26 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ajto(int *i, int *ajto_sz, int sp, int ajto_m)
{
	int kilincs_pos;

	kilincs_pos = ajto_m / 2;
	if ((sp == kilincs_pos) && (*ajto_sz == (ajto_m / 2) - 1) && ajto_m > 3)
		ft_putchar('$');
	else
		ft_putchar('|');
	*i += 1;
	*ajto_sz += 1;
}

int		sor_abr(int sor_nb, int sp, int ajto_meret)
{
	int i;
	int ajto_sz;

	ajto_sz = -ajto_meret / 2;
	i = 0;
	while (i < sp)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(47);
	i = 0;
	while (i <= sor_nb * 2)
	{
		while ((i == sor_nb + ajto_sz) && (sp < ajto_meret)
			&& (ajto_sz <= ajto_meret / 2))
			ajto(&i, &ajto_sz, sp, ajto_meret);
		ft_putchar('*');
		i += 1;
	}
	ft_putchar(92);
	ft_putchar('\n');
	return (sp - 1);
}

void	piramis(int sp, int ugr, int sor_ugr, int ajto_meret)
{
	int i;
	int leh_nb_ugr;
	int v_ugr;

	i = 0;
	v_ugr = 4;
	leh_nb_ugr = 1;
	while (sp + 1)
	{
		if (i == sor_ugr)
		{
			i += ugr;
			sp -= ugr;
			sor_ugr = i + v_ugr;
			v_ugr++;
			if (leh_nb_ugr == 2)
			{
				ugr++;
				leh_nb_ugr = 0;
			}
			leh_nb_ugr++;
		}
		sp = sor_abr(i, sp, ajto_meret);
		i++;
	}
}

void	sastantua(int meret)
{
	int sp;
	int ugr;
	int sor_ugr;
	int i;
	int z;

	i = 1;
	z = 0;
	ugr = 2;
	sor_ugr = 3;
	if (meret > 0)
	{
		while (i <= meret)
		{
			sp = sp + 6 + z;
			if (i > 1)
				z++;
			if ((i > 1) && (i % 2))
				z++;
			i++;
		}
		if (!(meret % 2))
			meret -= 1;
		piramis(sp - 4, ugr, sor_ugr, meret);
	}
}

int		main(void)
{
	sastantua(5);
	return (0);
}
