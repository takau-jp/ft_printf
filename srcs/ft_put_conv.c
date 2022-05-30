/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:22:44 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/29 17:04:21 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_c(t_print	*print, va_list *ap);
char	*ft_conv_s(char *buf, va_list *ap);

char	*ft_put_conversion(t_print	*print, char conv, va_list *ap)
{
	if (conv == 'c')
		return (ft_conv_c(print, ap));
	if (conv == 's')
		return (ft_conv_s(print->buf, ap));
	if (conv == '%')
		return (ft_join_char(print->buf, '%'));
	if (conv == 'p')
	{
		print->buf = ft_strjoin_free(print->buf, "0x");
		if (!print->buf)
			return (NULL);
		return (ft_join_address(print->buf, va_arg(*ap, unsigned long)));
	}
	if (conv == 'd' || conv == 'i')
		return (ft_join_nbr(print->buf, va_arg(*ap, int)));
	if (conv == 'u')
		return (ft_join_uint(print->buf, va_arg(*ap, unsigned int)));
	if (conv == 'x')
		return (ft_join_lower_hexa(print->buf, va_arg(*ap, unsigned int)));
	if (conv == 'X')
		return (ft_join_upper_hexa(print->buf, va_arg(*ap, unsigned int)));
	return (NULL);
}

char	*ft_conv_c(t_print	*print, va_list *ap)
{
	int	c;

	c = va_arg(*ap, int);
	if (!c)
	{
		print->null_char = true;
		return (print->buf);
	}
	return (ft_join_char(print->buf, c));
}

char	*ft_conv_s(char *buf, va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	return (ft_strjoin_free(buf, s));
}
