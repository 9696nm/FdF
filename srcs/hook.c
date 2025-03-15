/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:17 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/20 20:05:53 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	float		dx;
	float		dy;
	t_quater	rot_x;
	t_quater	rot_y;

	if ((vars->gflag.fl & (1 << MOUSE_PRESS)) == 0)
		return (0);
	dx = (vars->mcrd.press_x) - x;
	dy = y - (vars->mcrd.press_y);
	rot_x = quater_axis_angle(0.0, 1.0, 0.0, dx * MOUSE_SENSITIVITY);
	rot_y = quater_axis_angle(1.0, 0.0, 0.0, dy * MOUSE_SENSITIVITY);
	rot_x = quater_normalize(rot_x);
	rot_y = quater_normalize(rot_y);
	vars->rqv = quater_multiply(rot_x, quater_multiply(rot_y, vars->qv));
	vars->gflag.fl |= (1 << RE_GRAPHIC);
	return (0);
}

int	mouse_release(int button, int x __attribute__((unused)),
	int y __attribute__((unused)), t_vars *vars)
{
	if (button == Button1)
	{
		vars->gflag.fl &= ~(1 << MOUSE_PRESS);
		vars->qv = vars->rqv;
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	if (button == Button1)
	{
		vars->mcrd.press_x = x;
		vars->mcrd.press_y = y;
		vars->gflag.fl |= (1 << MOUSE_PRESS);
	}
	else if (button == Button4)
		vars->param.zoom += WHEEL_SPPED;
	else if (button == Button5)
		vars->param.zoom -= WHEEL_SPPED;
	else
		return (0);
	vars->gflag.fl |= (1 << RE_GRAPHIC);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (window_destroy(vars));
	if (keycode == XK_Up)
		vars->arrof = crd_off_move(vars->rqv, vars->arrof, (t_vec3){0, 1, 0});
	else if (keycode == XK_Down)
		vars->arrof = crd_off_move(vars->rqv, vars->arrof, (t_vec3){0, -1, 0});
	else if (keycode == XK_Left)
		vars->arrof = crd_off_move(vars->rqv, vars->arrof, (t_vec3){1, 0, 0});
	else if (keycode == XK_Right)
		vars->arrof = crd_off_move(vars->rqv, vars->arrof, (t_vec3){-1, 0, 0});
	else if (keycode == XK_period)
		vars->arrof.z_elast += 0.1;
	else if (keycode == XK_comma)
		vars->arrof.z_elast -= 0.1;
	else if (keycode == XK_slash)
		vars->gflag.fl ^= (1 << TOGGLE_PERSPECTIVE);
	else if (keycode == XK_0)
		parameter_init(vars);
	else
		return (0);
	vars->gflag.fl |= (1 << RE_GRAPHIC);
	return (0);
}

int	window_destroy(t_vars *vars)
{
	ft_putstr_fd("window close\n", STDOUT_FILENO);
	mlx_destroy_image(vars->mlx, vars->idata.img);
	return (mlx_loop_end(vars->mlx));
}
