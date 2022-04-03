/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:13:43 by stanaka           #+#    #+#             */
/*   Updated: 2022/04/02 22:26:35 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_conv_n(int res, t_conv *conv, va_list *ap)
{
	int	*arg;

	ft_conv_arg(conv, ap);
	arg = va_arg(*ap, int *);
	*arg = res;
	return (0);
}
