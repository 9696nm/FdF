/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:32:12 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/17 12:29:09 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_idata *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || WIDTH <= x || y < 0 || HEIGHT <= y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_line(t_idata *idata, t_coord q1, t_coord q2)
{
	int		steps;
	float	dx;
	float	dy;

	dx = q2.crd_x - q1.crd_x;
	dy = q2.crd_y - q1.crd_y;
	steps = fabs(dx);
	if (steps < fabs(dy))
		steps = fabs(dy);
	dx = dx / steps;
	dy = dy / steps;
	while (steps--)
	{
		my_mlx_pixel_put(idata, roundf(q1.crd_x), roundf(q1.crd_y), 0xFFFFFFFF);
		q1.crd_x += dx;
		q1.crd_y += dy;
	}
}

static t_quater	render_len(int mx, int my, t_idata *newimg, t_vars *vars)
{
	t_quater	q;
	t_quater	next;

	q = quater_rotate(vars->qv,
			quaternion_axis_angle(mx - vars->set.x, my - vars->set.y,
				(vars->set.z - vars->mat_arr[my][mx + 1]) * 0.1, M_PI));
	if (mx + 1 < vars->mat_arr[my][0])
	{
		next = render_len(mx + 1, my, newimg, vars);
		put_line(newimg, set_coord(q.x * vars->set.zoom + WIDTH / 2,
				q.y * vars->set.zoom + HEIGHT / 2, q.z),
			set_coord(next.x * vars->set.zoom + WIDTH / 2,
				next.y * vars->set.zoom + HEIGHT / 2, next.z));
	}
	if (vars->mat_arr[my + 1])
	{
		next = quater_rotate(vars->qv, quaternion_axis_angle(mx - vars->set.x,
					my + 1 - vars->set.y,
					(vars->set.z - vars->mat_arr[my + 1][mx + 1]) * 0.1, M_PI));
		put_line(newimg, set_coord(q.x * vars->set.zoom + WIDTH / 2,
				q.y * vars->set.zoom + HEIGHT / 2, q.z),
			set_coord(next.x * vars->set.zoom + WIDTH / 2,
				next.y * vars->set.zoom + HEIGHT / 2, next.z));
	}
	return (q);
}

static int	render_frame(t_vars *vars)
{
	int			len;
	t_idata		newimg;

	if (vars->gflag.refresh == GLAPH_ON)
	{
		vars->gflag.refresh = GLAPH_OFF;
		newimg.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
		newimg.addr = mlx_get_data_addr(newimg.img, &newimg.bits_per_pixel,
				&newimg.size_line, &newimg.endian);
		len = 0;
		while (vars->mat_arr[len])
			render_len(0, len++, &newimg, vars);
		mlx_put_image_to_window(vars->mlx, vars->win, newimg.img, 0, 0);
		mlx_destroy_image(vars->mlx, vars->idata.img);
		vars->idata = newimg;
	}
	return (0);
}

void	mlx(char *name, int **mat_arr)
{
	t_vars	vars;

	vars.mat_arr = mat_arr;
	vars.qv = quater_normalize(quaternion_axis_angle
			(1, 1, 1, -30 * M_PI / 180));
	vars.set = set_trans(mat_arr);
	vars.set.zoom = 20;
	vars.gflag.refresh = GLAPH_ON;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, name);
	vars.idata.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.idata.addr = mlx_get_data_addr(vars.idata.img,
			&vars.idata.bits_per_pixel,
			&vars.idata.size_line, &vars.idata.endian);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_press, &vars);
	mlx_hook(vars.win, DestroyNotify, SubstructureNotifyMask, window_destroy,
		&vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, mouse_press, &vars);
	mlx_hook(vars.win, ButtonRelease, ButtonReleaseMask, mouse_release, &vars);
	mlx_hook(vars.win, MotionNotify, PointerMotionMask, mouse_move, &vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
