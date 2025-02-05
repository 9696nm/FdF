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

static t_eanglef	set_axis(float axis_x, float axis_y, float axis_z)
{
	t_eanglef	axis;

	axis.ang_x = axis_x;
	axis.ang_y = axis_y;
	axis.ang_z = axis_z;
	return (axis);
}

static t_tarns	set_trans(int trans_x, int trans_y, int trans_z)
{
	t_tarns	offset;

	offset.set_x = trans_x;
	offset.set_y = trans_y;
	offset.set_z = trans_z;
	return (offset);
}

void	mlx(char *name, int **mat_arr)
{
	t_vars		vars;
	t_eanglef	axis;
	t_tarns		set;
	t_coord		crd;

	int zoom = 50;

	axis = set_axis(0, 0, 0);
	set = set_trans(5, 5, 0);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, name);
	vars.idata.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.idata.addr = mlx_get_data_addr(vars.idata.img, &vars.idata.bits_per_pixel, &vars.idata.size_line,
			&vars.idata.endian);
	for (int mat_y=0; mat_arr[mat_y]; mat_y++)
	{
		for (int mat_x=0; mat_x<mat_arr[mat_y][0]; mat_x++)
		{
			crd = rotate_matrix(mat_x-set.set_x, mat_y-set.set_y, mat_arr[mat_y][mat_x+1]-set.set_z, axis);
			// if (mat_arr[mat_y + 1])
			// 	put_line(&vars.idata, crd, rotate_matrix(mat_x-set.set_x, mat_y+1-set.set_y, mat_arr[mat_y+1][mat_x+1]-set.set_z, axis), 0);
			// if (mat_x + 1 < mat_arr[mat_y][0])
			// 	put_line(&vars.idata, crd, rotate_matrix(mat_x+1-set.set_x, mat_y-set.set_y, mat_arr[mat_y][mat_x+1+1]-set.set_z, axis), 0);
			if (crd.depth < 0)
				my_mlx_pixel_put(&vars.idata, crd.crd_x*zoom+WIDTH/2, crd.crd_y*zoom+HEIGHT/2, 0xFFFF00FF);
			else
				my_mlx_pixel_put(&vars.idata, crd.crd_x*zoom+WIDTH/2, crd.crd_y*zoom+HEIGHT/2, 0xFF00FFFF);
			printf("x:%+fy:%+fz:%+f ", crd.crd_x, crd.crd_y, crd.depth);
		}
		printf("\n");
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.idata.img, 0, 0);
	mlx_hook(vars.win, KeyPress, KeyPressMask, window_close, &vars);
	mlx_loop(vars.mlx);
}

			// my_mlx_pixel_put(&vars.idata, (int)(rotate_x(rotate_x(mat_x-or_x, mat_y-or_y, axis.ang_z), mat_arr[mat_y][mat_x+1]*or_z, axis.ang_y)*zoom+WIDTH/2),
			// 	(int)(rotate_x(rotate_y(mat_x-or_x, mat_y-or_y, axis.ang_z), mat_arr[mat_y][mat_x+1]*or_z, axis.ang_x)*zoom+HEIGHT/2), 0xFFFFFFFF); //+(mat_y*20<<24)
	// my_mlx_pixel_put(&vars.idata, 0, 0, 0xFFFFFFFF);
