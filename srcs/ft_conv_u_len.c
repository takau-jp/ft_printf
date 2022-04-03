/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:48:24 by stanaka           #+#    #+#             */
/*   Updated: 2022/02/20 20:39:45 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_put_u_len(t_conv *conv, uintmax_t d, int len, int padding);
int		ft_print_u_len(uintmax_t d, int padding);

int	ft_conv_u_len(t_conv *conv, va_list *ap)
{
	uintmax_t			num;
	int					len;
	int					padding;

	ft_conv_arg(conv, ap);
	if (!ft_conv_ulen(conv, ap, &num))
		return (0);
	len = ft_get_digits_uintmax(num, 10);
	if (conv->has_prec && conv->prec == 0 && num == 0)
		len = 0;
	padding = 0;
	if (len < conv->prec)
		padding = conv->prec - len;
	len += padding;
	return (ft_put_u_len(conv, num, len, padding));
}

int	ft_put_u_len(t_conv *conv, uintmax_t num, int len, int padding)
{
	int	res;

	res = 0;
	if (conv->has_prec && conv->prec == 0 && num == 0)
		return (ft_put_width_space(conv, len));
	if (conv->space_flags == '0' && conv->has_prec == false)
		res += ft_put_width_zero(conv, len);
	else if (conv->space_flags != '-')
		res += ft_put_width_space(conv, len);
	res += ft_print_u_len(num, padding);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	ft_print_u_len(uintmax_t num, int padding)
{
	int	res;

	res = 0;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 10)
		res += ft_print_u_len(num / 10, padding);
	res += ft_putchar("0123456789"[num % 10]);
	return (res);
}
