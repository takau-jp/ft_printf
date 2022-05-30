/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_intmax_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:44:45 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/29 17:22:08 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

uintmax_t	ft_abs_intmax(intmax_t i)
{
	uintmax_t	u;

	u = i;
	if (i < 0)
		u = ~i + 1;
	return (u);
}
