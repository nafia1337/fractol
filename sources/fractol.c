#include "fractal_shape_func.h"
#include "utils.h"
#include "events.h"

static int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}
void    myperror(char *error)
{
    write(2, error, ft_strlen(error));
    write(2, "\n", 1);
    exit(0);
}

void	validateparams( int argc ,char **argv, t_vars *vars)
{

	if (argc == 1)
	{
		myperror("./fractal <julia> <number1> <number2> \nOR\n./fractal <mandelbrot>");
	}
	if (!strcmp(argv[1] , "julia"))
	{
		vars->fractal = "julia";
		if (argc == 4 && isdigit_str(argv[2]) && isdigit_str(argv[3]))
		{
			vars->param_x = converttofloat(argv[2]);	
			vars->param_y = converttofloat(argv[3]);	
		}
		else
		{
			myperror("./fractal <julia> <number1> <number2>");
		}
	}
	else if ( argc == 2 && !strcmp(argv[1] , "mandelbrot"))	
		vars->fractal = "mandelbrot";
	else
		myperror("./fractal <mandelbort>");
}

int main(int argc, char *argv[]) 
{

        int pixel_bits;
        int line_bytes;
        int endian;
	t_vars vars;

	vars.mv_shape_x = 0.0;
	vars.mv_shape_y = 0.0;
	vars.Xmin = -2.f;
	vars.Xmax = +2.f;
	vars.Ymin = +2.f;
	vars.Ymax = -2.f;
	vars.zoom = 1;
	validateparams(argc, argv, &vars);
	vars.mlx = mlx_init();
        vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Tutorial Window - Create Image");
        vars.image = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
        vars.buffer = mlx_get_data_addr(vars.image, &pixel_bits, &line_bytes, &endian);
	vars.max_iter = 1000;
	render_shape(&vars);
	register_event(&vars);
	mlx_loop(vars.mlx);
}
