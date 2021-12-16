/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:01:38 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/16 19:52:54 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_address(unsigned long num);

int	ft_put_p(t_conv *conv, va_list *ap)
{
	int				res;
	unsigned long	address;
	int				len;

	address = va_arg(*ap, unsigned long);
	len = ft_get_digits_ulong(address, 16);
	res = ft_put_width_space(conv, len + 2);
	if (address == 0)
		return (res += ft_putstr("0x0"));
	res += ft_putstr("0x");
	return (res + ft_put_address(address));
}

int	ft_put_address(unsigned long num)
{
	int	res;

	res = 0;
	if (num >= 16)
		res += ft_put_address(num / 16);
	res += ft_putchar("0123456789abcdef"[num % 16]);
	return (res);
}
