/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:17 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/13 21:40:23 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	float	var_x;
	float	var_y;
	float	abs_xy;

	if (vars->gflag.mouse_press == MOUSE_PRESS_OFF)
		return (0);
	var_x = x - (vars->mcrd.press_x);
	var_y = (vars->mcrd.press_y) - y;
	abs_xy = 1 / sqrtf(var_x * var_x + var_y * var_y);
	if (isnan(abs_xy) || isinf(abs_xy))
		abs_xy = 0;
	vars->qv = quater_multiply(quater_normalize(quaternion_axis_angle
				(var_x * abs_xy, var_y * abs_xy, 0, M_PI / 100)), vars->qv);
	vars->gflag.refresh = GLAPH_ON;
	return (0);
}

int	mouse_release(int button, int x, int y, t_vars *vars)
{
	if (button == Button1)
		vars->gflag.mouse_press = MOUSE_PRESS_OFF;
	return (0);
}

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	if (button == Button1)
	{
		vars->mcrd.press_x = x;
		vars->mcrd.press_y = y;
		vars->gflag.mouse_press = MOUSE_PRESS_ON;
	}
	else if (button == Button4)
		vars->set.zoom += 2;
	else if (button == Button5)
		vars->set.zoom -= 2;
	else
		return (0);
	vars->gflag.refresh = GLAPH_ON;
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		window_destroy(vars);
	if (keycode == XK_Up)
		vars->set = reverse_quater(vars->qv, set_quat(0, 0, 1, 0), vars->set);
	else if (keycode == XK_Down)
		vars->set = reverse_quater(vars->qv, set_quat(0, 0, -1, 0), vars->set);
	else if (keycode == XK_Left)
		vars->set = reverse_quater(vars->qv, set_quat(0, 1, 0, 0), vars->set);
	else if (keycode == XK_Right)
		vars->set = reverse_quater(vars->qv, set_quat(0, -1, 0, 0), vars->set);
	else if (keycode == XK_0)
	{
		vars->qv = quater_normalize
			(quaternion_axis_angle(1, 1, 1, -30 * M_PI / 180));
		vars->set = set_trans(vars->mat_arr);
		vars->set.zoom = 20;
	}
	else
		return (0);
	vars->gflag.refresh = GLAPH_ON;
	return (0);
}

int	window_destroy(t_vars *vars)
{
	ft_putstr_fd("window close\n", STDOUT_FILENO);
	mlx_destroy_image(vars->mlx, vars->idata.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
	return (0);
}
