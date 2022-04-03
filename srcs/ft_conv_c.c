/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:35:48 by stanaka           #+#    #+#             */
/*   Updated: 2022/02/20 18:52:26 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_conv_c(t_conv *conv, va_list *ap)
{
	int	res;
	int	c;

	res = 0;
	ft_conv_arg(conv, ap);
	c = va_arg(*ap, int);
	if (!conv->space_flags)
		res += ft_put_width_space(conv, 1);
	if (conv->space_flags == '0')
		res += ft_put_width_zero(conv, 1);
	res += ft_putchar(c);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, 1);
	return (res);
}