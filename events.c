#include "fractal_shape_func.h"

void    close_fract(t_vars *vars)
{
        mlx_destroy_image(vars->mlx, vars->image);
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        exit(0);
}


int     mouse_handlers(int button, int x, int y, t_vars *vars)
{
        if (button == Button1) // left zoom out
        {
                vars->zoom *= 1.1;
        }
        else if (button == Button3) // middle deep zoom in
        {
                vars->zoom *= 0.95;
       }
        render_shape(vars);
        return (0);
}

void    *register_event(t_vars *vars)
{

        mlx_hook(vars->win, KeyPress, KeyPressMask, key_handler, vars);
        mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_handlers, vars);
}

int     key_handler(int keysym, t_vars *vars)
{
        if (keysym == XK_Escape)
        {
                close_fract(vars);
                //exit(0);
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
