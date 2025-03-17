#include "fractal_shape_func.h"

double  *linespace(double xmin, double xmax, int width)
{
        double	*x;
        double	step;
        int	i;

        x = (double *)malloc( width * sizeof(double));
        if (NULL == x)
                exit(0); //we cant allocate memory
        step = ( ((double)xmax - xmin) / ((double)width - 1));
        i = 0;
        while (i < width)
        {
                if (i == 0)
                        x[i] = xmin;
                else
                        x[i] = x[i-1] + step;
                i++;
        }
        return (x);
}


void *render_shape(t_vars *vars)
{

        cp_num c;

int color_palette[][3] = {
    {240, 222, 194}, // Ivory
    {245, 245, 220}, // Linen
    {250, 250, 230}, // Antique white
    {255, 255, 255}, // White
    {200, 200, 200}, // Light gray
    {150, 150, 150}, // Gray
    {100, 100, 100}, // Dark gray
    {50, 50, 50},     // Very dark gray
    {0, 0, 0}         // Black
};



        vars->x = linespace(vars->Xmin * vars->zoom, vars->Xmax * vars->zoom, WIDTH);

        vars->y = linespace(vars->Ymin * vars->zoom, vars->Ymax * vars->zoom, HEIGHT);

        for(int i = 0; i < HEIGHT; ++i)
{
                for(int j = 0; j < WIDTH; ++j)
        {

                int pixel = (i * WIDTH + j) * 4;
		unsigned int	color;
                c.real_nb = vars->x[j] + vars->mv_shape_x;
                c.imaginary_nb = vars->y[i] + vars->mv_shape_y;
		if (!strcmp(vars->fractal, "mandelbrot"))
			color = mandelbrot_calc(c, vars->max_iter);
		else	
                	color = julia_calc(c, vars->max_iter, vars);

                int color_index = (unsigned int )color % sizeof(color_palette) / sizeof(color_palette[0]);
                vars->buffer[pixel + 0] = color_palette[color_index][0] ;
                vars->buffer[pixel + 1] =  color_palette[color_index][1] ;
                vars->buffer[pixel + 2] =  color_palette[color_index][2] ;
                vars->buffer[pixel + 3] = 255;
        }
}
        mlx_put_image_to_window(vars->mlx, vars->win, vars->image, 0, 0);
}

unsigned int mandelbrot_calc(cp_num c, int max_iter)
{
        cp_num  z;
        int     n;
        double  magnitude;

        z.real_nb = c.real_nb;
        z.imaginary_nb = c.imaginary_nb;

        n = 0;
        while ( n < max_iter)
        {
                magnitude = hypot(z.real_nb, z.imaginary_nb);
                if (fabs(magnitude) > 2.0)
                {

                        return (n);
                }

        // update the new z value
        double temp = z.imaginary_nb;
        z.imaginary_nb = z.real_nb * z.imaginary_nb * 2 + c.imaginary_nb;
        z.real_nb = pow(z.real_nb, 2) - pow(temp, 2) + c.real_nb;
        n++;
        }

        //return (dist_to_origine);
        return (max_iter);
}

double  convertToFloat(char *str_float)
{
	int	i;
	int	counter;
	int 	rest_float;
	double	res;
	double	res2;
	int	sign ;
	
	counter = 0;
	rest_float = 0;
	res = 0;
	res2 = 0;
	i = 0;
	sign = 1;
	while (str_float[i])
	{
		if(str_float[i] == '-')
		{
			sign = sign * -1;
			i++;
			continue;
		}
		if (str_float[i] == '.')
		{
			rest_float = 1;
			i++;
			continue;
		}
		if (!rest_float)
			res = res * 10 + (str_float[i] - 48);
		else
		{
			res2 = res2 * 10 + (str_float[i] - 48);
			counter++;
		}	
		i++;	
	}
	res2 = res2 / (pow(10, counter));
	res = res + res2;
	return (res * sign);

}

unsigned int	julia_calc(cp_num z, int max_iter, t_vars *vars)
{
        cp_num  z_0;
        //cp_num  c = {-0.8f, 0.156f};
        cp_num  c = {vars->param_x, vars->param_y};
        int     n;
        double  magnitude;

        z_0.real_nb = z.real_nb;
        z_0.imaginary_nb = z.imaginary_nb;
        n = 0;
        while ( n < max_iter)
        {
                magnitude = hypot(z_0.real_nb, z_0.imaginary_nb);
                if (fabs(magnitude) > 2.0)
                {
                        return (n);
                }
        double temp = z_0.imaginary_nb;
        z_0.imaginary_nb = z_0.real_nb * z_0.imaginary_nb * 2 + c.imaginary_nb;
        z_0.real_nb = pow(z_0.real_nb, 2) - pow(temp, 2) + c.real_nb;
        n++;
        }
        return (max_iter); // intensity
}


int	isdigit_str(char * str)
{
	int	i;
	int	is_float;

	i = 0;
	is_float = 0;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			is_float = 1;
		}
		else if (str[i] == '.' || str[i] == '-')
		{	
			is_float = 1;
		}
		else
		{
			is_float = 0;
		}
		
		if (is_float == 0 && i != 0)
			return (is_float);
		i++;	
	}
	return (is_float);
}
