# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molla <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 09:30:30 by molla             #+#    #+#              #
#    Updated: 2023/02/26 14:54:46 by molla            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif
LIBFT		= Libft/
MLX			= mlx/
SRCS		= so_long.c check_map.c check_map_utils.c check_map_utils_2.c \
			imgs_init.c function_utils.c mvt.c mvt_utils.c
SRCSBONUS	= bonus/so_long_bonus.c bonus/check_map_bonus.c \
			bonus/check_map_utils_bonus.c bonus/check_map_utils_2_bonus.c \
			bonus/imgs_init_bonus.c bonus/function_utils_bonus.c \
			bonus/mvt_bonus.c bonus/mvt_utils_bonus.c bonus/anim_bonus.c \
			bonus/put_init_bonus.c bonus/print_evol_bonus.c \
			bonus/mvt_mob_bonus.c bonus/mvt_utils_mob_bonus.c \
			bonus/mvt_utils_DK_bonus.c bonus/jag_imgs_init_bonus.c \
			bonus/mvt_utils_2_bonus.c bonus/mvt_utils_mob_2_bonus.c
OBJS		= ${SRCS:.c=.o}
OBJSBONUS	= ${SRCSBONUS:.c=.o}
NAME		= so_long

all : ${NAME}
	
${NAME} : ${OBJS}
	${MAKE} -C ${LIBFT}
	${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit $^ ${LIBFT}libft.a -o $@

%.o : %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

clean :
	rm -f ${OBJS} ${OBJSBONUS}
	${MAKE} clean -C ${LIBFT}
	${MAKE} clean -C ${MLX}

fclean : clean
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFT}

debug :
	${MAKE} DEBUG=1

re : fclean all

bonus : ${OBJSBONUS}
	${MAKE} -C ${LIBFT}
	${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit $^ ${LIBFT}libft.a -o ${NAME}

.PHONY : all clean fclean re