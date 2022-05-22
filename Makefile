# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 18:49:53 by stanaka           #+#    #+#              #
#    Updated: 2022/05/22 20:55:56 by stanaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a

SRCDIR	= ./srcs
BONUS_SRCDIR = ./bonus

SRCS	= ft_printf.c
SRCS	+= ${addprefix ${SRCDIR}/, ${addsuffix .c, ft_put_conv ft_join_utils ft_join_utils2 ft_abs ft_strchr ft_strlen ft_memcpy ft_memset}}
BONUS_SRCS	= ft_printf_bonus.c
BONUS_SRCS	+= ${addprefix ${BONUS_SRCDIR}/, ${addsuffix _bonus.c, ft_array_calc ft_conv_a ft_conv_a2 ft_conv_a3 ft_conv_c ft_conv_d ft_conv_d_len ft_conv_e \
			 ft_conv_e2 ft_conv_e3 ft_conv_e4 ft_conv_o ft_conv_o_len ft_conv_p ft_conv_percent ft_conv_u ft_conv_u_len \
			 ft_conv_utils ft_conv_s ft_conv_x ft_conv_x_len \
			 ft_conv_f ft_conv_f2 ft_conv_g ft_conv_ge ft_conv_ge2 ft_conv_ge3 ft_conv_gf ft_conv_gf2 ft_double_utils ft_double_utils2 ft_double_utils3 \
			 ft_conv_n ft_conv_n_len ft_get_digits ft_get_digits_long ft_hex_array_calc ft_put_conv ft_put_width_space ft_read_conv ft_read_conv_utils \
			 ft_join_utils ft_print ft_print_buf \
			 ft_abs_intmax ft_putchar ft_putstr ft_putstrl ft_putnbr ft_strcmp}}

OBJDIR	= ./objs
M_OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}
B_OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${BONUS_SRCS:.c=.o}}}

ifdef BONUS
OBJS = $(B_OBJS)
else
OBJS = $(M_OBJS)
endif

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	ar src $(NAME) $(OBJS)

${OBJDIR}/%.o: %.c
	-mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/%.o: ${BONUS_SRCDIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@

all:
	$(NAME)

${LIBFT}:
	@make -C $(LIBFT_DIR)

bonus:
	@make BONUS=1

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(M_OBJS) $(B_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME) ${OBJDIR}

re: fclean all

.PHONY: all bonus clean fclean re
