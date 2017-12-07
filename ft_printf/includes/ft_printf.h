/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkis <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:08:22 by bkis              #+#    #+#             */
/*   Updated: 2017/07/05 16:37:02 by bkis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PF t_printf
# define SPE t_spec
# define BUFF_MAX 4096
# define FD 1
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

char	g_buff[BUFF_MAX];
int		g_i;

typedef struct s_printf	t_printf;
typedef struct s_spec	t_spec;

struct	s_printf
{
	char			*format;
	size_t			index;
	unsigned char	spec;
	int				flags[13];
	char			*arg;
	wchar_t			*warg;
	int				ret;
};

struct	s_spec
{
	int (*spe[128])(PF*, va_list);
};

int		ft_printf(const char *format, ...);

void	ft_display(PF *argument);
void	*ft_buff(char *str, PF *argument);
void	ft_buf(char c, PF *argument);
int		ft_print_character(PF *argument);
int		ft_print_str(PF *argument);
int		ft_print_number(PF *argument, char *pre);

void	ft_free(PF *argument);
void	ft_init_buff();
PF		*ft_init_argument(PF *argument);
void	ft_init_spe_tab(SPE *spe);

char	*ft_strnew(size_t size);
int		ft_tolower(int c);
int		ft_wcharlen(wchar_t wchar);
size_t	ft_wbytelen(wchar_t *ws);
void	*ft_strlower(char *s);
int		ft_atoi(const char *nbr);
char	*ft_itoa_base(uintmax_t nbr, int base);
int		ft_wchartostr(char *s, wchar_t wc);
void	ft_nputchar(char c, ssize_t n, PF *argument);
size_t	ft_strlen(const char *s);
size_t	ft_wstrlen(wchar_t *s);
int		ft_wstrtostr(char *s, wchar_t *wstr, int n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char	*ft_strsub_with_free(char const *s, unsigned int start, size_t len);
char	*ft_transform_wchar_in_char(wchar_t *ws);
int		ft_putwchar_in_char(wchar_t wchar, char *fresh, int i);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *dest, int c, size_t n);
int		ft_isescaped(char c);
int		ft_isdigit(int c);

int		signed_handler(PF *argument, va_list ap);
int		pointer_handler(PF *argument, va_list ap);
int		character_handler(PF *argument, va_list ap);
int		string_handler(PF *argument, va_list ap);
int		unsigned_handler(PF *argument, va_list ap);
int		ft_arg_nospe(PF *argument, va_list ap);
int		prc_handler(PF *argument, va_list ap);

int		ft_wildcard(PF *argument, va_list ap, int index);
int		ft_get_flags(PF *argu, va_list ap);
int		ft_check_flags(PF *argu);
int		ft_check_width(PF *argu, va_list ap);
int		ft_check_precision(PF *argument, va_list ap);
void	ft_check_length(PF *argu);
int		ft_check_spec(PF *argument);
int		ft_check_spec_bis(PF *argument);

#endif
