/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:51:16 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/02 21:11:16 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <inttypes.h>

# include "libft.h"

# define CONV "cspdiuxX\%"

typedef struct s_print
{
	int		res;
	char	*buf;
	bool	null_char;
}	t_print;

int				ft_printf(const char *format, ...);
char			*ft_put_conversion(t_print *print, char conv, va_list *ap);
char			*ft_join_address(char *buf, uintptr_t num);
char			*ft_join_uint(char *buf, unsigned int num);
char			*ft_join_lower_hexa(char *buf, unsigned int num);
char			*ft_join_upper_hexa(char *buf, unsigned int num);
int				ft_putchar(char c);
char			*ft_join_char(char *buf, char c);
size_t			ft_putstr(char *str);
char			*ft_join_nbr(char *buf, int n);
char			*ft_strjoin_free(char *s1, char *s2);

#endif
