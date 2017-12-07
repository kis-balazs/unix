/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:25:46 by bkis              #+#    #+#             */
/*   Updated: 2017/07/07 13:25:48 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int						reset_fd(int fd, char *new_fd)
{
	int					new;

	close(fd);
	new = open(new_fd, O_RDWR | O_CREAT | O_APPEND, 0666);
	return (new);
}

char					*get_pwd(void)
{
	char		*pwd;
	char		*buff;
	long		size;

	buff = NULL;
	size = 1024;
	pwd = NULL;
	if ((buff = (char *)malloc((size_t)size)) != NULL)
		pwd = getcwd(buff, (size_t)size);
	return (pwd);
}

char					**copy_env(void)
{
	t_llist				*ptr;
	char				**cpy;
	int					count;

	count = 0;
	if (g_env != NULL)
	{
		ptr = g_env;
		cpy = (char**)malloc(sizeof(char*) * g_memory.env_lenght + 1);
		while (count < g_memory.env_lenght - 1)
		{
			cpy[count] = ft_strdup(ptr->content);
			count++;
			ptr = ptr->next;
		}
		cpy[count] = ft_strdup(ptr->content);
		cpy[g_memory.env_lenght] = NULL;
		return (cpy);
	}
	return (NULL);
}

void					*ft_realloc(void *mem, size_t size)
{
	char				*buff;

	buff = NULL;
	if (mem == NULL)
		return (malloc(size));
	if (size <= 0)
		return (NULL);
	buff = (void*)malloc(size);
	if (buff)
		ft_memcpy(buff, mem, size);
	free(mem);
	return (buff);
}

void					free_d(char **dtab, int lenght)
{
	int					i;

	i = 0;
	while (i < lenght)
	{
		free(dtab[i]);
		i++;
	}
}
