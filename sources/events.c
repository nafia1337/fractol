/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnafia <bnafia@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:09:50 by bnafia            #+#    #+#             */
/*   Updated: 2025/03/21 10:16:08 by bnafia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_shape_func.h"
#include "events.h"
#define ZOOM_IN 4
#define ZOOM_OUT 5

int	close_fract(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

int	mouse_handlers(int button, t_vars *vars)
{
	if (button == ZOOM_OUT)
	{
		vars->zoom *= 1.1;
	}
	else if (button == ZOOM_IN)
	{
		vars->zoom *= 0.95;
	}
	render_shape(vars);
	return (0);
}

void	register_event(t_vars *vars)
{
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, close_fract, vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, key_handler, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_handlers, vars);
}

int	key_handler(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		close_fract(vars);
	}
	else
	{
		if (keysym == XK_Left)
			vars->mv_shape_x += 0.5;
		if (keysym == XK_Right)
			vars->mv_shape_x -= 0.5;
		if (keysym == XK_Up)
			vars->mv_shape_y -= 0.5;
		if (keysym == XK_Down)
			vars->mv_shape_y += 0.5;
		printf("%d\n", keysym);
		render_shape(vars);
	}
	return (0);
}
