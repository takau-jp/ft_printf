/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:51:37 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/02 20:51:16 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	char	*itr;
	t_print	print;
	t_conv	conv;
	va_list	ap;

	itr = (char *)format;
	if (!itr)
		return (-1);
	va_start(ap, format);
	ft_memset(&print, 0, sizeof(print));
	print.res = ft_print(itr, &print, &conv, &ap);
	va_end(ap);
	return (print.res);
}
