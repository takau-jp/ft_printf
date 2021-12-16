/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:53:25 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/16 19:56:19 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_x(t_conv *conv, va_list *ap)
{
	int				res;
	unsigned int	d;
	int				len;
	int				padding;

	d = va_arg(*ap, unsigned int);
	len = ft_get_digits_uint(d, 16);
	if (conv->has_precision && conv->precision == 0 && d == 0)
		len = 0;
	padding = 0;
	if (len < conv->precision)
		padding = conv->precision - len;
	len += padding;
	res = ft_put_width_space(conv, len);
	if (conv->has_precision && conv->precision == 0 && d == 0)
		return (res);
	return (res + ft_put_lower_hexa(d, padding));
}

int	ft_put_lower_hexa(int d, int padding)
{
	int				res;
	unsigned int	num;

	res = 0;
	num = d;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 16)
		res += ft_put_lower_hexa(num / 16, padding);
	res += ft_putchar("0123456789abcdef"[num % 16]);
	return (res);
}

int	ft_put_X(t_conv *conv, va_list *ap)
{
	int				res;
	unsigned int	d;
	int				len;
	int				padding;

	d = va_arg(*ap, unsigned int);
	len = ft_get_digits_uint(d, 16);
	if (conv->has_precision && conv->precision == 0 && d == 0)
		len = 0;
	padding = 0;
	if (len < conv->precision)
		padding = conv->precision - len;
	len += padding;
	res = ft_put_width_space(conv, len);
	if (conv->has_precision && conv->precision == 0 && d == 0)
		return (res);
	return (res + ft_put_upper_hexa(d, padding));
}

int	ft_put_upper_hexa(int d, int padding)
{
	int				res;
	unsigned int	num;

	res = 0;
	num = d;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 16)
		res += ft_put_upper_hexa(num / 16, padding);
	res += ft_putchar("0123456789ABCDEF"[num % 16]);
	return (res);
}
