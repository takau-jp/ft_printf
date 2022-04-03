# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 18:49:53 by stanaka           #+#    #+#              #
#    Updated: 2022/04/03 10:06:33 by stanaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCDIR	= ./srcs
LIBDIR	= ./libft
SRCS	= ft_printf.c
SRCS	+= ${addprefix ${SRCDIR}/, ft_array_calc.c ft_conv_a.c ft_conv_a2.c ft_conv_a3.c ft_conv_c.c ft_conv_d.c ft_conv_d_len.c ft_conv_e.c \
			 ft_conv_e2.c ft_conv_e3.c ft_conv_e4.c ft_conv_o.c ft_conv_o_len.c ft_conv_p.c ft_conv_percent.c ft_conv_u.c ft_conv_u_len.c \
			 ft_conv_utils.c ft_conv_s.c ft_conv_x.c ft_conv_x_len.c \
			 ft_conv_f.c ft_conv_f2.c ft_conv_g.c ft_conv_ge.c ft_conv_ge2.c ft_conv_ge3.c ft_conv_gf.c ft_conv_gf2.c ft_double_utils.c ft_double_utils2.c ft_double_utils3.c \
			 ft_conv_n.c ft_conv_n_len.c ft_get_digits.c ft_get_digits_long.c ft_hex_array_calc.c ft_put_conv.c ft_put_width_space.c ft_read_conv.c}
SRCS	+= ${addprefix ${LIBDIR}/, ft_abs.c ft_abs_intmax.c ft_atoi.c ft_isdigit.c ft_isspace.c ft_labs.c ft_memcpy.c ft_memset.c\
			 ft_putchar.c ft_putstr.c ft_putstrl.c ft_putnbr.c ft_strchr.c ft_strlen.c ft_strcmp.c ft_strnlen.c}
OBJDIR	= ./objs
OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar src $(NAME) $(OBJS)

${OBJDIR}/%.o: %.c
	-mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/%.o: ${LIBDIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

bonus: all

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) ${OBJDIR}

re: fclean all

.PHONY: all clean fclean re