# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 21:02:54 by amenses-          #+#    #+#              #
#    Updated: 2022/11/14 01:33:17 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_putstr_fd.c\
					ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strjoin.c ft_itoa.c ft_putnbr_fd.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c  ft_isascii.c ft_putendl_fd.c \
					ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_putchar_fd.c \
					ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_split.c \

SRCS_BONUS		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
					ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS			= $(SRCS:.c=.o)

OBJS_BONUS		= ${SRCS_BONUS:.c=.o}

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

bonus:			$(OBJS) $(OBJS_BONUS)
					ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
					$(RM) $(NAME)

re:					fclean $(NAME)

so:
				$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCS_BONUS)
				gcc -nostartfiles -shared -o libft.so $(OBJS) $(SRCS_BONUS)

.PHONY:			all clean fclean re bonus