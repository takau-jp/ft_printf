/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_calc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:13:41 by stanaka           #+#    #+#             */
/*   Updated: 2022/05/29 17:22:13 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	array_add(int8_t *a, int8_t *b, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		a[i] += b[i];
		if (a[i] >= 10 && i != 0)
		{
			a[i] -= 10;
			a[i - 1] += 1;
		}
		if (a[i] >= 10 && i == 0)
			a[i] -= 10;
		i--;
	}
}

void	array_half(int8_t *n, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		n[i + 1] += (n[i] % 2) * 10;
		n[i] /= 2;
		i++;
	}
}

void	array_double(int8_t *n, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		n[i] *= 2;
		if (i < size - 1 && n[i + 1] >= 10)
		{
			n[i] += 1;
			n[i + 1] -= 10;
		}
		i--;
	}
}
