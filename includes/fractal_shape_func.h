/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_shape_func.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafia <bnafia@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:54:58 by bnafia            #+#    #+#             */
/*   Updated: 2025/03/21 10:05:18 by bnafia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_SHAPE_FUNC_H
# define FRACTAL_SHAPE_FUNC_H
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <ctype.h>
# include <string.h>
# define HEIGHT 600
# define WIDTH 600

typedef struct s_complex_number
{
	double	real_nb;
	double	imaginary_nb;
}	cp_num;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*image;
	double	mv_shape_x;
	double	mv_shape_y;
	int	max_iter;
	char	*buffer;
	double	*x;
	double	*y;
	double	zoom;
	double	Xmin;
	double	Xmax;
	double	Ymin;
	double	Ymax;
	double	param_x;
	double	param_y;
	char	*fractal;
}	t_vars;

unsigned int	mandelbrot_calc(cp_num c, int max_iter);
unsigned int     julia_calc(cp_num z, int max_iter, t_vars *vars);
void    	render_shape(t_vars *vars);
void		validateparams(int argc, char **argv, t_vars *vars);

#endif
