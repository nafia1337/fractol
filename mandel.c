#include "fractal_shape_func.h"

void	validateparams(char **argv, t_vars *vars)

{
	if (!strcmp(argv[1] , "julia"))
	{
		vars->fractal = "julia";
		if (isdigit_str(argv[2]) && isdigit_str(argv[3]))
		{
			vars->param_x = convertToFloat(argv[2]);	
			vars->param_y = convertToFloat(argv[3]);	
		}
		else
		{
			exit(0);
		}

	}

	else if (!strcmp(argv[1] , "mandelbrot"))	
		vars->fractal = "mandelbrot";
	else
		exit(0);	
}

int main(int argc, char *argv[]) 

{

        int pixel_bits;
        int line_bytes;
        int endian;
	unsigned int color;
        double *x, *y;
        cp_num c;
	t_vars vars;

	vars.mv_shape_x = 0.0;
	vars.mv_shape_y = 0.0;
	vars.Xmin = -2.f;
	vars.Xmax = +2.f;

	vars.Ymin = +2.f;
	vars.Ymax = -2.f;

	vars.zoom = 1;
        
	validateparams(argv, &vars);
	vars.mlx = mlx_init();
        vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Tutorial Window - Create Image");
        vars.image = mlx_new_image(vars.mlx, WIDTH, HEIGHT);

        vars.buffer = mlx_get_data_addr(vars.image, &pixel_bits, &line_bytes, &endian);
        
	vars.max_iter = 1000;
	

	render_shape(&vars);
	
	register_event(&vars);
	
	mlx_loop(vars.mlx);
}
