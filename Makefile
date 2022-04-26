NAME := cub3d

INCLUDES 		:= ./includes
PATH_SRC 		:= ./src

PATH_LIBFT 		:= ${INCLUDES}/libft
libftincludes 	:= ${PATH_LIBFT}/
libft.a 		:= ${PATH_LIBFT}/libft.a

PATH_GNL		:=$(INCLUDES)/gnl
gnlincludes 	:= ${PATH_GNL}/
gnl.a 			:=$(PATH_GNL)/gnl.a

PATH_MLX 		:=${INCLUDES}/mlx
mlxincludes 	:=${PATH_MLX}/
mlx.add			:=${PATH_MLX}/libmlx.a


SRC 			:= ./src/cub3d.c\
					./src/exit.c\
					./src/free.c\
					./src/ft_multijoin.c\
					./src/init.c\
					./src/utils.c\
					./src/utils2.c\
					./src/utils3.c\
					./src/utilsparam.c\
					./src/parserfile.c\
					./src/parsermap.c\
					./src/hookkey.c\
					./src/draw.c\
					./src/utilsdraw.c\



OBJS 			:=${SRC:.c=.o}

CFLAG  			:=-Wall -Wextra -Werror -g -fsanitize=address
MY_CPPFLAGS		:=-I${INCLUDES} -I${libftincludes} -I${gnlincludes} -I${mlxincludes}

CC 				:= gcc
CFLAGS			:=${CFLAG} ${MY_CFLAGS} 
CPPFLAGS		:=${MY_CPPFLAGS}
LDLIBS     		:=$(libft.a) ${gnl.a} ${mlx.a} -lm -framework OpenGL -framework AppKit
RM 				:= rm -rf


all:
	@$(MAKE) -j $(NAME)

${NAME}: ${OBJS}
			@$(MAKE) -j -C includes/libft/ bonus
			@$(MAKE) -j -C includes/gnl/
			@$(MAKE) -j -C includes/mlx/
			$(CC) $(LDLIBS) $(CFLAGS) ${OBJS} includes/libft/libft.a includes/gnl/gnl.a includes/mlx/libmlx.a -o ${NAME}

%.o : %.c
		${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $<

clean:
			@$(MAKE) -s --no-print-directory -C includes/libft/ clean
			@$(MAKE) -s --no-print-directory -C includes/gnl/ clean
			@$(MAKE) -j -C includes/mlx/ clean
			${RM} ${OBJS}

fclean: 	clean
			@$(MAKE) -s --no-print-directory -C includes/libft/ fclean
			@$(MAKE) -s --no-print-directory -C includes/gnl/ fclean
			@$(MAKE) -j -C includes/mlx/ clean
			${RM} ${NAME}

re: 		fclean all
			@$(MAKE) -s --no-print-directory -C includes/libft/ re
			@$(MAKE) -s --no-print-directory -C includes/gnl/ re
			@$(MAKE) -j -C includes/mlx/ re

.PHONY: all clean fclean re