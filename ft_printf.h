/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:51:16 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/16 20:07:51 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

# define CONV "cspdiuxX%"

typedef struct s_conv
{
	int		c;
	int		width;
	bool	has_precision;
	int		precision;
}	t_conv;

int				ft_printf(const char *format, ...);
int				ft_put_c(t_conv *conv, va_list *ap);
int				ft_put_d(t_conv *conv, va_list *ap);
int				ft_put_p(t_conv *conv, va_list *ap);
int				ft_put_u(t_conv *conv, va_list *ap);
int				ft_put_s(t_conv *conv, va_list *ap);
int				ft_put_x(t_conv *conv, va_list *ap);
int				ft_put_lower_hexa(int d, int padding);
int				ft_put_X(t_conv *conv, va_list *ap);
int				ft_put_upper_hexa(int d, int padding);
int				ft_put_width_space(t_conv *conv, size_t len);
int				ft_get_digits(int n, int base);
int				ft_get_digits_uint(unsigned int n, int base);
int				ft_get_digits_long(long n, int base);
int				ft_get_digits_ulong(unsigned long n, int base);
unsigned int	ft_abs(int i);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);
unsigned long	ft_labs(long i);
int				ft_putchar(char c);
size_t			ft_putstr(char *str);
size_t			ft_putstrl(char *str, size_t len);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(char *s, size_t n);

#endif