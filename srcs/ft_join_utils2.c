/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:26:30 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/29 17:07:34 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_join_nbr(char *buf, int n)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		buf = ft_strjoin_free(buf, "-");
		if (!buf)
			return (NULL);
		num = ft_abs(n);
	}
	if (num >= 10)
	{
		buf = ft_join_nbr(buf, num / 10);
		if (!buf)
			return (NULL);
	}
	return (ft_join_char(buf, "0123456789"[num % 10]));
}

char	*ft_join_uint(char *buf, unsigned int num)
{
	if (num >= 10)
	{
		buf = ft_join_uint(buf, num / 10);
		if (!buf)
			return (NULL);
	}
	return (ft_join_char(buf, "0123456789"[num % 10]));
}

char	*ft_join_address(char *buf, unsigned long num)
{
	if (num >= 16)
	{
		buf = ft_join_address(buf, num / 16);
		if (!buf)
			return (NULL);
	}
	return (ft_join_char(buf, "0123456789abcdef"[num % 16]));
}

char	*ft_join_lower_hexa(char *buf, unsigned int num)
{
	if (num >= 16)
	{
		buf = ft_join_lower_hexa(buf, num / 16);
		if (!buf)
			return (NULL);
	}
	return (ft_join_char(buf, "0123456789abcdef"[num % 16]));
}

char	*ft_join_upper_hexa(char *buf, unsigned int num)
{
	if (num >= 16)
	{
		buf = ft_join_upper_hexa(buf, num / 16);
		if (!buf)
			return (NULL);
	}
	return (ft_join_char(buf, "0123456789ABCDEF"[num % 16]));
}
