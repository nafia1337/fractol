PROG = fract

SRCS = sources/fractol.c \
       sources/events.c \
       sources/utils.c \
       sources/fractal_shape_func.c

INC = -Iincludes

INC_2 = -I./libft/includes

INC_3 = -I./minilibx/

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

OBJS = ${SRCS:.c=.o}

all: ${PROG}

${PROG}: ${OBJS}
	##make  -C ./libft
	##${CC} ${OBJS} -Llibft -lft  minilibx/libmlx_Linux.a -I./minilibx -lXext -lX11 -lm -o ${PROG}
	${CC} ${OBJS} minilibx/libmlx_Linux.a -I./minilibx -lXext -lX11 -lm -o ${PROG}
%.o: %.c
	##${CC} ${CFLAGS} -c $< ${INC_2} ${INC} -o $@
	${CC} ${CFLAGS} -c $< ${INC_3} ${INC} -o $@
fclean: clean
	rm -f ${PROG}
	##make fclean -C ./libft

clean:
	rm -f ${OBJS}
	##make clean -C ./libft

re: fclean all
