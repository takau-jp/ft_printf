/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:51:16 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/22 09:54:10 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# define CONV "cspdiuxX\%"

typedef struct s_print
{
	int		res;
	char	*buf;
	bool	null_char;
}	t_print;

int				ft_printf(const char *format, ...);
char			*ft_put_conversion(t_print *print, char conv, va_list *ap);
char			*ft_join_address(char *buf, unsigned long num);
char			*ft_join_uint(char *buf, unsigned int num);
char			*ft_join_lower_hexa(char *buf, unsigned int num);
char			*ft_join_upper_hexa(char *buf, unsigned int num);
unsigned int	ft_abs(int i);
int				ft_isdigit(int c);
int				ft_putchar(char c);
char			*ft_join_char(char *buf, char c);
size_t			ft_putstr(char *str);
char			*ft_join_nbr(char *buf, int n);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
char			*ft_strjoin_free(char *s1, char *s2);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *buf, int ch, size_t n);

#endif
