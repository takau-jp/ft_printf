/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:51:37 by stanaka           #+#    #+#             */
/*   Updated: 2022/02/22 11:14:09 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_conversion(t_conv *conv);

int	ft_printf(const char *restrict format, ...)
{
	char	*itr;
	int		res;
	t_conv	conv;
	va_list	ap;

	res = 0;
	itr = (char *)format;
	if (!itr)
		return (-1);
	va_start(ap, format);
	while (*itr)
	{
		if (*itr == '%')
		{
			ft_init_conversion(&conv);
			itr = ft_read_conversion(&conv, ++itr);
			if (!itr)
				return (-1);
			res += ft_put_conversion(&conv, &ap, res);
			continue ;
		}
		res += ft_putchar(*itr++);
	}
	va_end(ap);
	return (res);
}

void	ft_init_conversion(t_conv *conv)
{
	conv->hash_flag = 0;
	conv->space_flags = 0;
	conv->sign_flags = 0;
	conv->width = 0;
	conv->width_arg = 0;
	conv->has_prec = false;
	conv->prec = 0;
	conv->prec_arg = 0;
	conv->length[0] = 0;
	conv->length[1] = 0;
	conv->length[2] = '\0';
	conv->c = 0;
}
