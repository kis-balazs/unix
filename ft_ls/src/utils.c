/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:43:37 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:38:21 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*fts_date(time_t const *clock)
{
	char	*date;
	char	*t_buf;
	time_t	act;

	date = ft_strnew(13);
	t_buf = ctime(clock);
	date = ft_strncpy(date, t_buf + 4, 12);
	if ((time(&act) - *clock) >= 13042800 || act < *clock)
		ft_strncpy(date + 7, t_buf + 19, 5);
	return (date);
}

char		*epure_name(char *fname, t_params opts)
{
	char *slash;

	if (!(opts & FULL_NAMES) && (slash = ft_strrchr(fname, '/')))
		slash = (*(slash + 1)) ? slash + 1 : fname;
	else
		slash = fname;
	return (slash);
}

char		*maj_min(struct stat stated)
{
	char	*ret;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_itoa(major(stated.st_rdev));
	tmp2 = ft_itoa(minor(stated.st_rdev));
	if (minor(stated.st_rdev) < 10)
		tmp3 = ft_strjoin(tmp, ",   ");
	else if (minor(stated.st_rdev) < 100)
		tmp3 = ft_strjoin(tmp, ",  ");
	else
		tmp3 = ft_strjoin(tmp, ", ");
	ret = ft_strjoin(tmp3, tmp2);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (ret);
}

char		*lnk_name(char *fname, char *full_name)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strnew(255);
	tmp[readlink(full_name, tmp, 255)] = 0;
	tmp2 = ft_strjoin(" -> ", tmp);
	tmp3 = fname;
	fname = ft_strjoin(fname, tmp2);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (fname);
}
