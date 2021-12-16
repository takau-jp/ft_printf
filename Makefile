# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 18:49:53 by stanaka           #+#    #+#              #
#    Updated: 2021/12/16 21:47:30 by stanaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCDIR	= ./srcs
LIBDIR	= ./libft
SRCS	= ft_printf.c
SRCS	+= ${addprefix ${SRCDIR}/, ft_put_c.c ft_put_d.c ft_put_p.c ft_put_u.c ft_put_s.c ft_put_x.c \
			 ft_get_digits.c ft_get_digits_long.c ft_put_width_space.c}
SRCS	+= ${addprefix ${LIBDIR}/, ft_abs.c ft_atoi.c ft_isdigit.c ft_isspace.c ft_labs.c \
			 ft_putchar.c ft_putstr.c ft_putstrl.c ft_strchr.c ft_strlen.c ft_strnlen.c}
OBJDIR	= ./objs
OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

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

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} $(OBJS)

fclean: clean
	${RM} $(NAME)
	rm -rf ${OBJDIR}

re: fclean all

.PHONY: all clean fclean re