/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:45:21 by bkis              #+#    #+#             */
/*   Updated: 2017/05/15 16:45:22 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->prev = (*alst)->prev;
	new->next = (*alst);
	if ((*alst)->prev)
		(*alst)->prev->next = new;
	else
		*alst = new;
	(*alst)->prev = new;
}

int		ft_lstinsert_list(t_list *fflist, t_list *ffnew,
		int (*f)(t_list*, t_list*))
{
	t_list		*tmp;
	t_list		*end_new;
	int			ret;

	if (!fflist)
	{
		fflist = ffnew;
		return (0);
	}
	ret = 0;
	tmp = fflist;
	end_new = ffnew;
	while (((f)(ffnew, tmp)) > 0 && tmp->next)
		tmp = tmp->next;
	while (end_new->next && ++ret)
		end_new = end_new->next;
	if (tmp->next)
	{
		ffnew->prev = tmp;
		end_new->next = tmp->next;
	}
	else
		ffnew->prev = tmp;
	tmp->next = ffnew;
	return (ret);
}

t_list	*ft_lstinsert(t_list **fflist, t_list *new, int (*f)(t_list*, t_list*))
{
	t_list		*tmp;
	int			comp;

	if (!*fflist)
		return ((*fflist = new));
	tmp = (*fflist);
	while (((comp = (f)(new, tmp))) > 0 && tmp->next)
		tmp = tmp->next;
	if (comp > 0)
	{
		tmp->next ? tmp->next->prev = (t_list*)new : 0;
		tmp->next = new;
		new->prev = tmp;
	}
	else
	{
		new->prev = tmp->prev;
		new->next = tmp;
		tmp->prev ? tmp->prev->next = new :
			(*fflist = new);
		tmp->prev = new;
	}
	return (new);
}

void	ft_lstappend(t_list *alst, t_list *new)
{
	t_list	*tmp;

	if (!new || !alst)
		return ;
	tmp = alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
