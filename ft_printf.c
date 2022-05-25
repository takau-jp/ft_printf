/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:51:37 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/25 15:42:12 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print(va_list *ap, char *itr);
void	buf_init(t_print *print);
char	*read_format(va_list *ap, char *itr, t_print *print);
void	print_buf(t_print *print);

int	ft_printf(const char *format, ...)
{
	char	*itr;
	int		res;
	va_list	ap;

	itr = (char *)format;
	if (!itr)
		return (-1);
	va_start(ap, format);
	res = ft_print(&ap, itr);
	va_end(ap);
	return (res);
}

int	ft_print(va_list *ap, char *itr)
{
	t_print	print;

	ft_memset(&print, 0, sizeof(print));
	while (*itr)
	{
		buf_init(&print);
		if (!print.buf)
			return (-1);
		itr = read_format(ap, itr, &print);
		if (!itr)
			return (-1);
		print_buf(&print);
		free(print.buf);
		if (print.res == -1)
			return (-1);
	}
	return (print.res);
}

void	buf_init(t_print *print)
{
	print->buf = malloc(sizeof(char) * 1);
	if (!print->buf)
		return ;
	print->buf[0] = '\0';
}

char	*read_format(va_list *ap, char *itr, t_print *print)
{
	while (*itr && *itr != '%')
	{
		print->buf = ft_join_char(print->buf, *itr++);
		if (!print->buf)
			return (NULL);
	}
	if (*itr == '%')
	{
		if (!ft_strchr(CONV, *++itr))
		{
			free(print->buf);
			return (NULL);
		}
		print->buf = ft_put_conversion(print, *itr++, ap);
		if (!print->buf)
			return (NULL);
	}
	return (itr);
}

void	print_buf(t_print *print)
{
	size_t	buf_len;

	buf_len = ft_strlen(print->buf);
	if (print->res + buf_len + print->null_char >= INT_MAX)
	{
		print->res = -1;
		return ;
	}
	print->res += write(1, print->buf, buf_len);
	if (print->null_char)
	{
		print->res += write(1, "\0", 1);
		print->null_char = false;
	}
}
