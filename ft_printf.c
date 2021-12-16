/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:51:37 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/16 21:36:25 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_conversion(t_conv *conv);
char	*ft_read_conversion(t_conv *conv, char *itr);
int		ft_put_conversion(t_conv *conv, va_list *ap);

int	ft_printf(const char *restrict format, ...)
{
	char	*itr;
	int		res;
	t_conv	conv;
	va_list	ap;

	itr = (char *)format;
	if (!itr)
		return (-1);
	va_start(ap, format);
	res = 0;
	while (*itr)
	{
		if (*itr == '%')
		{
			ft_init_conversion(&conv);
			itr = ft_read_conversion(&conv, ++itr);
			if (!itr)
				return (-1);
			res += ft_put_conversion(&conv, &ap);
			continue ;
		}
		res += ft_putchar(*itr++);
	}
	va_end(ap);
	return (res);
}

void	ft_init_conversion(t_conv *conv)
{
	conv->c = 0;
	conv->width = 0;
	conv->has_precision = false;
	conv->precision = 0;
}

char	*ft_read_conversion(t_conv *conv, char *itr)
{
	if (!itr)
		return (NULL);
	if (ft_isdigit(*itr))
	{
		conv->width = ft_atoi(itr);
		itr += ft_get_digits(conv->width, 10);
	}
	if (*itr == '.')
	{
		conv->has_precision = true;
		itr++;
	}
	if (ft_isdigit(*itr))
	{
		conv->precision = ft_atoi(itr);
		itr += ft_get_digits(conv->precision, 10);
	}
	if (ft_strchr(CONV, *itr))
		conv->c = *itr++;
	else
		return (NULL);
	return (itr);
}

int	ft_put_conversion(t_conv *conv, va_list *ap)
{
	if (conv->c == 'c')
		return (ft_put_c(conv, ap));
	if (conv->c == 's')
		return (ft_put_s(conv, ap));
	if (conv->c == 'p')
		return (ft_put_p(conv, ap));
	if (conv->c == 'd' || conv->c == 'i')
		return (ft_put_d(conv, ap));
	if (conv->c == 'u')
		return (ft_put_u(conv, ap));
	if (conv->c == 'x')
		return (ft_put_x(conv, ap));
	if (conv->c == 'X')
		return (ft_put_X(conv, ap));
	if (conv->c == '%')
		return (ft_put_width_space(conv, 1) + ft_putchar('%'));
	return (0);
}
