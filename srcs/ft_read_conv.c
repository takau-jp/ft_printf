/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:42:06 by stanaka           #+#    #+#             */
/*   Updated: 2022/02/22 11:15:57 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_read_flag(t_conv *conv, char *itr);
char	*ft_read_width(t_conv *conv, char *itr);
char	*ft_read_precision(t_conv *conv, char *itr);
char	*ft_read_length(t_conv *conv, char *itr);

char	*ft_read_conversion(t_conv *conv, char *itr)
{
	if (!itr)
		return (NULL);
	itr = ft_read_flag(conv, itr);
	itr = ft_read_width(conv, itr);
	itr = ft_read_precision(conv, itr);
	itr = ft_read_length(conv, itr);
	if (ft_strchr(CONV, *itr))
		conv->c = *itr++;
	else
		return (NULL);
	return (itr);
}

char	*ft_read_flag(t_conv *conv, char *itr)
{
	while (ft_strchr(FLAGS, *itr))
	{
		if (*itr == '#')
			conv->hash_flag = *itr;
		else if (*itr == '+' || *itr == ' ')
		{
			if (conv->sign_flags != '+')
				conv->sign_flags = *itr;
		}
		else
		{
			if (conv->space_flags != '-')
				conv->space_flags = *itr;
		}
		itr++;
	}
	return (itr);
}

char	*ft_read_width(t_conv *conv, char *itr)
{
	if (*itr == '*')
	{
		conv->width_arg = '*';
		itr++;
	}
	else if (ft_isdigit(*itr))
	{
		conv->width = ft_atoi(itr);
		itr += ft_get_digits(conv->width, 10);
	}
	return (itr);
}

char	*ft_read_precision(t_conv *conv, char *itr)
{
	if (*itr == '.')
	{
		conv->has_prec = true;
		itr++;
	}
	if (*itr == '*')
	{
		conv->prec_arg = '*';
		itr++;
	}
	else if (ft_isdigit(*itr))
	{
		conv->prec = ft_atoi(itr);
		while (*itr == '0')
			itr++;
		if (!ft_isdigit(*itr))
			itr--;
		itr += ft_get_digits(conv->prec, 10);
	}
	return (itr);
}

char	*ft_read_length(t_conv *conv, char *itr)
{
	if (ft_strchr(LENGTH, *itr))
	{
		conv->length[0] = *itr;
		itr++;
		if (conv->length[0] == 'h' && *itr == 'h')
		{
			conv->length[1] = *itr;
			itr++;
		}
		else if (conv->length[0] == 'l' && *itr == 'l')
		{
			conv->length[1] = *itr;
			itr++;
		}
	}
	return (itr);
}
