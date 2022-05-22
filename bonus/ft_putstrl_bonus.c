/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:09:48 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/22 17:04:05 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

size_t	ft_putstrl(char *str, size_t len)
{
	size_t	res;
	size_t	i;

	if (!str)
		return (0);
	res = 0;
	i = ft_strnlen(str, len);
	while (INT_MAX < i)
	{
		res += write(1, str, INT_MAX);
		str += INT_MAX;
		i -= INT_MAX;
	}
	res += write(1, str, i);
	return (res);
}
