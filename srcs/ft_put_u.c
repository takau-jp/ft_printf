/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:56:23 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/16 19:54:25 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_uint(unsigned int d, int padding);

int	ft_put_u(t_conv *conv, va_list *ap)
{
	unsigned int	res;
	unsigned int	d;
	int				len;
	int				padding;

	d = va_arg(*ap, unsigned int);
	len = ft_get_digits_uint(d, 10);
	if (conv->has_precision && conv->precision == 0 && d == 0)
		len = 0;
	padding = 0;
	if (len < conv->precision)
		padding = conv->precision - len;
	len += padding;
	res = ft_put_width_space(conv, len);
	if (conv->has_precision && conv->precision == 0 && d == 0)
		return (res);
	return (res + ft_put_uint(d, padding));
}

int	ft_put_uint(unsigned int d, int padding)
{
	int				res;

	res = 0;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (d >= 10)
		res += ft_put_uint(d / 10, padding);
	res += ft_putchar("0123456789"[d % 10]);
	return (res);
}
