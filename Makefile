all:
	gcc -g mandel.c events.c fractal_shape_func.c minilibx/libmlx_Linux.a -I./minilibx -lXext -lX11 -lm -o mandel
