# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataverni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 16:58:36 by ataverni          #+#    #+#              #
#    Updated: 2021/04/24 16:58:44 by ataverni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c		ft_strmapi.c	ft_atoi.c \
	 		ft_putchar_fd.c	ft_strncmp.c	ft_bzero.c \
			ft_putendl_fd.c	ft_strnstr.c	ft_calloc.c \
		  	ft_putnbr_fd.c	ft_strrchr.c 	ft_strlen.c \
			ft_isalnum.c	ft_putstr_fd.c	ft_memmove.c \
			ft_strtrim.c	ft_isalpha.c	ft_strlcpy.c \
			ft_split.c		ft_substr.c		ft_isascii.c \
			ft_strchr.c		ft_tolower.c	ft_isdigit.c \
			ft_memccpy.c	ft_strdup.c		ft_toupper.c \
			ft_isprint.c	ft_memchr.c		ft_strjoin.c \
			ft_itoa.c		ft_memcmp.c		ft_strlcat.c \
			ft_memcpy.c			

B_SRCS	= 	ft_lstclear.c	ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c	ft_lstdelone.c		ft_lstiter.c \
			ft_lstmap.c		ft_lstnew.c			ft_lstadd_back.c \
			ft_strcpy.c		ft_strcmp_bonus.c 	ft_putstr_bonus.c \
			ft_putnbr_bonus.c 

OBJS	=	${SRCS:.c=.o}

B_OBJS	=	${B_SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

NAME	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

${NAME}:	${OBJS}
		ar -rcs ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJS} ${B_OBJS}
		ar -rcs ${NAME} $^

clean:
		rm -f ${OBJS} ${B_OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all bonus clean fclean re
