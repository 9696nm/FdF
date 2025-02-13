/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:32:12 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/02 11:32:13 by hana/hmori       ###   ########.fr       */
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

void	put_line(t_idata *idata, t_coord q1, t_coord q2, int thickness)
{
	int steps;
	float dx;
	float dy;

	dx = q2.crd_x - q1.crd_x;
	dy = q2.crd_y - q1.crd_y;
	steps = fabs(dx);
	if (steps < fabs(dy))
		steps = fabs(dy);
	dx = dx / steps;
	dy = dy / steps;
	while (steps--)
	{
		my_mlx_pixel_put(idata, roundf(q1.crd_x), roundf(q2.crd_x), 0xFFFFFFFF);
		q1.crd_x += dx;
		q1.crd_y += dy;
	}
}

static int	render_frame(t_vars *vars)
{
	t_quater	q;
	t_quater	qv;
	t_idata		newimg;

	if (vars->gflag.refresh == GLAPH_ON)
	{
		vars->gflag.refresh = GLAPH_OFF;
		newimg.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
		newimg.addr = mlx_get_data_addr(newimg.img, &newimg.bits_per_pixel, &newimg.size_line, &newimg.endian);
		qv = quater_multiply(vars->qv, vars->tmpqv);
		for (int my=0; vars->mat_arr[my]; my++)
		{
			for (int mx=0; mx<vars->mat_arr[my][0]; mx++)
			{
				q = quaternion_axis_angle(mx-vars->set.x, my-vars->set.y, vars->mat_arr[my][mx+1]-vars->set.z, M_PI);
				q = quater_rotate(qv, q);
				// put_line(&newimg, set_coord(q.x * vars->set.zoom + WIDTH / 2, q.y * vars->set.zoom + HEIGHT / 2), vars->mat_arr[my][0]), vars->set.zoom / 10);
				my_mlx_pixel_put(&newimg, q.x*vars->set.zoom+WIDTH/2, q.y*vars->set.zoom+HEIGHT/2, 0xFF0FF0FF);
			}
		}
		mlx_put_image_to_window(vars->mlx, vars->win, newimg.img, 0, 0);
		mlx_destroy_image(vars->mlx, vars->idata.img);
		vars->idata = newimg;
		printf("%d : ok!\n", vars->gflag.refresh);
	}
	return (0);
}

void	mlx(char *name, int **mat_arr)
{
	t_vars	vars;
	
	vars.mat_arr = mat_arr;
	vars.qv = quater_normalize(quaternion_axis_angle(1, 1, 1, 30 * M_PI / 180));
	vars.tmpqv = set_quater(1, 0, 0, 0);
	printf("w:%.2f x:%.2f y:%.2f z:%.2f\n", vars.qv.w, vars.qv.x, vars.qv.y, vars.qv.z);

	vars.set = set_trans(mat_arr);
	vars.set.zoom = 20;
	vars.gflag.refresh = GLAPH_ON;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, name);
	vars.idata.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.idata.addr = mlx_get_data_addr(vars.idata.img, &vars.idata.bits_per_pixel, &vars.idata.size_line,
		&vars.idata.endian);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_press, &vars);
	mlx_hook(vars.win, DestroyNotify, SubstructureNotifyMask, window_destroy, &vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, mouse_press, &vars);
	mlx_hook(vars.win, ButtonRelease, ButtonReleaseMask, mouse_release, &vars);
	mlx_hook(vars.win, MotionNotify, PointerMotionMask, mouse_move, &vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
}
	
	// my_mlx_pixel_put(&vars.idata, (int)(rotate_x(rotate_x(mat_x-or_x, mat_y-or_y, axis.ang_z), mat_arr[mat_y][mat_x+1]*or_z, axis.ang_y)*zoom+WIDTH/2),
	// 	(int)(rotate_x(rotate_y(mat_x-or_x, mat_y-or_y, axis.ang_z), mat_arr[mat_y][mat_x+1]*or_z, axis.ang_x)*zoom+HEIGHT/2), 0xFFFFFFFF); //+(mat_y*20<<24)
	// my_mlx_pixel_put(&vars.idata, 0, 0, 0xFFFFFFFF);
	