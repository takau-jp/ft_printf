/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:30:53 by stanaka           #+#    #+#             */
/*   Updated: 2022/02/21 14:44:52 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static bool				is_overflow_long(long *num, int sign, char c);

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == 0)
		i++;
	while (ft_isdigit(str[i]))
	{
		if (is_overflow_long(&num, sign, str[i]))
			return (num);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

static bool	is_overflow_long(long *num, int sign, char c)
{
	long	limit;

	limit = (long []){LONG_MIN, LONG_MAX}[sign == 1];
	if (*num > LONG_MAX / 10 || \
		(*num == LONG_MAX / 10 && c - '0' >= (int)(ft_labs(limit) % 10)))
	{
		*num = limit;
		return (true);
	}
	return (false);
}
