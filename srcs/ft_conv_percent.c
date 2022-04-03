/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:33:15 by stanaka           #+#    #+#             */
/*   Updated: 2022/02/11 13:20:22 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_conv_percent(t_conv *conv)
{
	int	res;

	res = 0;
	if (!conv->space_flags)
		res += ft_put_width_space(conv, 1);
	if (conv->space_flags == '0')
		res += ft_put_width_zero(conv, 1);
	res += ft_putchar('%');
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, 1);
	return (res);
}
