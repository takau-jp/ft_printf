/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:35:48 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/16 19:51:10 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_c(t_conv *conv, va_list *ap)
{
	int	c;

	c = va_arg(*ap, int);
	return (ft_put_width_space(conv, 1) + ft_putchar(c));
}
