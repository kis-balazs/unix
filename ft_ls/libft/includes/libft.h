/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:47:28 by bkis              #+#    #+#             */
/*   Updated: 2017/03/11 12:47:30 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 128

typedef struct		s_list
{
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef	struct		s_file
{
	int				fd;
	char			*buff;
	struct s_file	*nxt;
}					t_file;

void				ft_pmem(const void *addr, size_t t);
int					get_next_line(int const fd, char **line);
void				ft_swap(void *a, void *b);
void				ft_iswap(int *a, int *b);
int					ft_getndigits(int a);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_puthex(unsigned char num);
size_t				ft_strlen(const char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dest, char const *src, size_t size);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
int					ft_strcchr(char const *s, char c);
int					ft_strclchr(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(char const *s);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strinv(char *s);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_realloc(void **src, size_t src_size, size_t final_size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memmove(void *dest, void const *src, size_t len);
void				*ft_memccpy(void *dest, void const *src, int c, size_t n);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
char				*ft_itoa(int n);
int					ft_atoi(char const *s);
int					ft_pow(int n, int p);
unsigned int		ft_abs(signed int n);
int					ft_tabmax(int *tab, int siz);
int					ft_tolower(int c);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strnstr(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstinsert(t_list **fflist, t_list *new, \
		int (*f)(t_list*, t_list*));
void				ft_lstappend(t_list *alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *));
void				ft_lstdel(t_list **alst, void (*del)(void *));
int					ft_lstinsert_list(t_list *fflist, t_list *ffnew, \
		int (*f)(t_list*, t_list*));
#endif
