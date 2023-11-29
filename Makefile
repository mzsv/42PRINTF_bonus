# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 03:33:30 by amenses-          #+#    #+#              #
#    Updated: 2023/07/03 21:28:36 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

LIBFT			=	libft/libft.a

SRCS			=	ft_printf.c \
					ft_printf_utils_0.c ft_printf_utils_1.c \
					ft_printf_utils_2.c ft_printf_utils_3.c \
					ft_printf_utils_4.c ft_printf_utils_5.c \
					ft_printf_utils_6.c ft_printf_utils_7.c \

OBJS			=	$(SRCS:.c=.o)

NAME			=	libftprintf.a

all:				$(NAME)

$(NAME):			$(OBJS)
					$(MAKE) -C libft
					cp $(LIBFT) $(NAME)
					ar rcs $(NAME) $(OBJS)

bonus:				$(NAME)

clean:
					$(MAKE) clean -C libft
					$(RM) $(OBJS)

fclean:				clean
					$(MAKE) fclean -C libft
					$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:				all clean fclean re bonus
