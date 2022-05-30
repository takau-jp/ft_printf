/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:35:48 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/29 17:22:29 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_conv_c(t_print *print, t_conv *conv, va_list *ap)
{
	int	res;
	int	c;

	res = 0;
	c = va_arg(*ap, int);
	if (!ft_print_buf(print, conv, 1))
		return (-1);
	if (!conv->space_flags)
		res += ft_put_width_space(conv, 1);
	if (conv->space_flags == '0')
		res += ft_put_width_zero(conv, 1);
	res += ft_putchar(c);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, 1);
	return (res);
}
