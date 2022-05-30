/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:50:28 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/29 17:25:37 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr(int n)
{
	unsigned int	num;
	int				res;

	num = n;
	res = 0;
	if (n < 0)
	{
		res += write(1, "-", 1);
		num = ft_abs(n);
	}
	if (num >= 10)
		res += ft_putnbr(num / 10);
	res += write(1, &"0123456789"[num % 10], 1);
	return (res);
}
