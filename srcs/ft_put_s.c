/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:59:16 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/16 19:53:38 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_s(t_conv *conv, va_list *ap)
{
	int		res;
	size_t	len;
	char	*s;

	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (conv->has_precision && len > (size_t)conv->precision)
		len = conv->precision;
	res = ft_put_width_space(conv, len);
	return (res + ft_putstrl(s, len));
}
