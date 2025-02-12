/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:17 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/30 12:57:22 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	printf("x:%d y:%d\n", x, y);
	return (0);
}

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	printf("bot:%d x:%d y:%d\n", button, x, y);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		window_destroy(vars);
	if (keycode == XK_Up)
		vars->set.y += 1;
	else if (keycode == XK_Down)
		vars->set.y -= 1;
	else if (keycode == XK_Left)
		vars->set.x += 1;
	else if (keycode == XK_Right)
		vars->set.x -= 1;
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
	exit(0);
	return (0);
}
