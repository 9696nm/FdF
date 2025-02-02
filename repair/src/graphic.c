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

static void	my_mlx_pixel_put(t_idata *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || width <= x || y < 0 || height <= y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// static t_point	*set_axis(int **array, t_axis axis)
// {
// 	;
// }

// static void	set_pixel(t_axis axis)
// {

// }

void	mlx(int **array)
{
	t_vars	vars;
	t_axisf	axis;

	axis.ax = 0;
	axis.ay = 0;
	axis.az = 0;

	int zoom = 50;
	int	or_x = 5;
	int	or_y = 5;
	float	or_z = 0.3F;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "fdf");
	vars.idata.img = mlx_new_image(vars.mlx, width, height);
	vars.idata.addr = mlx_get_data_addr(vars.idata.img, &vars.idata.bits_per_pixel, &vars.idata.size_line,
			&vars.idata.endian);
	for (int ly=0; array[ly]; ly++)
		for (int lx=0; lx<array[ly][0]; lx++)
		{
			my_mlx_pixel_put(&vars.idata, (int)(rotate_x(rotate_x(lx-or_x, ly-or_y, axis.az), array[ly][lx+1]*or_z, axis.ay)*zoom+width/2),
				(int)(rotate_x(rotate_y(lx-or_x, ly-or_y, axis.az), array[ly][lx+1]*or_z, axis.ax)*zoom+height/2), 0xFFFFFFFF);//+(ly*20<<24)
		}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.idata.img, 0, 0);
	mlx_hook(vars.win, KeyPress, KeyPressMask, window_close, &vars);
	mlx_loop(vars.mlx);
}
