/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:43:18 by stanaka           #+#    #+#             */
/*   Updated: 2022/02/21 09:58:10 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	put_mydouble_sp_case(t_conv *conv, t_mydb *mydouble, int len);
int	print_mydouble_sp_case(t_mydb *mydouble);

void	convert_double_simple(t_mydb *mydouble)
{
	ft_memset(mydouble->decimal_frac, 0, sizeof(mydouble->decimal_frac));
	ft_memset(mydouble->decimal_int, 0, sizeof(mydouble->decimal_int));
	convert_int(mydouble);
	convert_frac(mydouble);
}

int	ft_double_sp_case(t_conv *conv, double num)
{
	t_mydb	mydouble;

	get_binary_double(&mydouble, num);
	if (mydouble.exp == 2047 && mydouble.frac != 0)
		return (put_mydouble_sp_case(conv, &mydouble, 3));
	else if (mydouble.sign == 0 && mydouble.exp == 2047)
		return (put_mydouble_sp_case(conv, &mydouble, 3));
	else if (mydouble.sign == 1 && mydouble.exp == 2047)
		return (put_mydouble_sp_case(conv, &mydouble, 4));
	return (0);
}

int	put_mydouble_sp_case(t_conv *conv, t_mydb *mydouble, int len)
{
	int	res;

	res = 0;
	if (!(mydouble->exp == 2047 && mydouble->frac != 0))
	{
		if (mydouble->sign == 0 && conv->sign_flags)
			len++;
	}
	if (conv->space_flags != '-')
		res += ft_put_width_space(conv, len);
	if (!(mydouble->exp == 2047 && mydouble->frac != 0))
	{
		if (mydouble->sign == 0 && conv->sign_flags == '+')
			res += ft_putchar('+');
		if (mydouble->sign == 0 && conv->sign_flags == ' ')
			res += ft_putchar(' ');
	}
	res += print_mydouble_sp_case(mydouble);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	print_mydouble_sp_case(t_mydb *mydouble)
{
	int	res;

	res = 0;
	if (mydouble->exp == 2047 && mydouble->frac != 0)
	{
		res += write(1, "nan", 3);
		return (res);
	}
	if (mydouble->sign == 1)
		res += write(1, "-", 1);
	if (mydouble->exp == 2047)
	{
		res += write(1, "inf", 3);
		return (res);
	}
	return (res);
}