/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:22:44 by stanaka           #+#    #+#             */
/*   Updated: 2022/04/02 23:52:37 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_etc_conv(t_conv *conv, va_list *ap, int res);
int	ft_put_decimal_conv(t_conv *conv, va_list *ap);
int	ft_put_float_conv(t_conv *conv, va_list *ap);

int	ft_put_conversion(t_conv *conv, va_list *ap, int res)
{
	if (ft_strchr("cs\%n", conv->c))
		return (ft_put_etc_conv(conv, ap, res));
	if (ft_strchr("pdDiuxXo", conv->c))
		return (ft_put_decimal_conv(conv, ap));
	if (ft_strchr("fFeEgGaA", conv->c))
		return (ft_put_float_conv(conv, ap));
	return (0);
}

int	ft_put_etc_conv(t_conv *conv, va_list *ap, int res)
{
	if (conv->length[0])
	{
		if (conv->c == 'n')
			return (ft_conv_n_len(res, conv, ap));
	}
	if (conv->c == 'c')
		return (ft_conv_c(conv, ap));
	if (conv->c == 's')
		return (ft_conv_s(conv, ap));
	if (conv->c == '%')
		return (ft_conv_percent(conv));
	if (conv->c == 'n')
		return (ft_conv_n(res, conv, ap));
	return (0);
}

int	ft_put_decimal_conv(t_conv *conv, va_list *ap)
{
	if (conv->length[0])
	{
		if (conv->c == 'd' || conv->c == 'D' || conv->c == 'i')
			return (ft_conv_d_len(conv, ap));
		if (conv->c == 'u')
			return (ft_conv_u_len(conv, ap));
		if (conv->c == 'x' || conv->c == 'X')
			return (ft_conv_x_len(conv, ap));
		if (conv->c == 'o')
			return (ft_conv_o_len(conv, ap));
	}
	if (conv->c == 'p')
		return (ft_conv_p(conv, ap));
	if (conv->c == 'd' || conv->c == 'D' || conv->c == 'i')
		return (ft_conv_d(conv, ap));
	if (conv->c == 'u')
		return (ft_conv_u(conv, ap));
	if (conv->c == 'x' || conv->c == 'X')
		return (ft_conv_x(conv, ap));
	if (conv->c == 'o')
		return (ft_conv_o(conv, ap));
	return (0);
}

int	ft_put_float_conv(t_conv *conv, va_list *ap)
{
	if (conv->c == 'f' || conv->c == 'F')
		return (ft_conv_f(conv, ap));
	if (conv->c == 'e' || conv->c == 'E')
		return (ft_conv_e(conv, ap));
	if (conv->c == 'g' || conv->c == 'G')
		return (ft_conv_g(conv, ap));
	if (conv->c == 'a' || conv->c == 'A')
		return (ft_conv_a(conv, ap));
	return (0);
}
