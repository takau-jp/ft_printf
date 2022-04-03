/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:16:22 by stanaka           #+#    #+#             */
/*   Updated: 2022/01/08 17:35:31 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_num(int d, int padding);

int	ft_put_d(t_conv *conv, va_list *ap)
{
	int	res;
	int	d;
	int	len;
	int	padding;

	d = va_arg(*ap, int);
	len = ft_get_digits(d, 10);
	if (conv->has_precision && conv->precision == 0 && d == 0)
		len = 0;
	padding = 0;
	if (d < 0 && len - 1 < conv->precision)
		padding = conv->precision - (len - 1);
	else if (len < conv->precision)
		padding = conv->precision - len;
	len += padding;
	res = 0;
	res = ft_put_width_space(conv, len);
	if (conv->has_precision && conv->precision == 0 && d == 0)
		return (res);
	return (res + ft_put_num(d, padding));
}

int	ft_put_num(int d, int padding)
{
	int				res;
	unsigned int	num;

	res = 0;
	num = ft_abs(d);
	if (d < 0)
		res += ft_putchar('-');
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 10)
		res += ft_put_num(num / 10, padding);
	res += ft_putchar("0123456789"[num % 10]);
	return (res);
}
