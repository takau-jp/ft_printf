/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width_space_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:14:52 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/13 01:37:04 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_put_width_space(t_conv *conv, size_t len)
{
	int	res;

	res = 0;
	while ((size_t)conv->width > len)
	{
		res += ft_putchar(' ');
		conv->width--;
	}
	return (res);
}

int	ft_put_width_zero(t_conv *conv, size_t len)
{
	int	res;

	res = 0;
	while ((size_t)conv->width > len)
	{
		res += ft_putchar('0');
		conv->width--;
	}
	return (res);
}
