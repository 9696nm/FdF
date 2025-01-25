/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:19:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/24 15:28:10 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static double rotate_x(double x, double y, double theta)
{
	return ((x)*cos(theta*M_PI/180)-(y)*sin(theta*M_PI/180));
}

static double rotate_y(double x, double y, double theta)
{
	return ((x)*sin(theta*M_PI/180)+(y)*cos(theta*M_PI/180));
}

static void	my_mlx_pixel_put(t_idata *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || SIZE_X <= x || y < 0 || SIZE_Y <= y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// static t_point	*set_axis(int **array, t_axis axis)
// {
// 	;
// }

static void	mlx(int **array)
{
	t_vars	vars;
	t_idata	img;

	t_axis	axis;

	axis.x = 0;
	axis.y = 0;
	axis.z = 0;

	int zoom = 50;
	int	or_x = 5;
	int	or_y = 5;
	double	or_z = 0.3;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIZE_X, SIZE_Y, "Hello world!");
	img.img = mlx_new_image(vars.mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
			&img.endian);
	for (int ly=0; array[ly]; ly++)
		for (int lx=0; lx<array[ly][0]; lx++)
		{
			my_mlx_pixel_put(&img, (int)(rotate_x(rotate_x(lx-or_x, ly-or_y, axis.z), array[ly][lx+1]*or_z, axis.y)*zoom+SIZE_X/2),
				(int)(rotate_x(rotate_y(lx-or_x, ly-or_y, axis.z), array[ly][lx+1]*or_z, axis.x)*zoom+SIZE_Y/2), 0xFFFFFFFF);//+(ly*20<<24)
		}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

static int **len_alloc(int length)
{
	int		**array;

	array = malloc(sizeof(int *) * (length + 1));
	array[length] = NULL;
	return (array);
}

static void	double_free(char **array)
{
	int	len;

	len = 0 ;
	while (array[len])
		free(array[len++]);
	free(array);
}

static int	**assig_arr(int fd, int length)
{
	int		width;
	int		*element;
	int		**array;
	char	*ret;
	char	**sp_arr;

	ret = get_next_line(fd);
	if (ret == NULL)
		return (len_alloc(length));
	sp_arr = ft_split(ret, ' ');
	free(ret);
	width = 0;
	while (ft_strchr(sp_arr[width], '\n') == NULL)
		width++;
	element = malloc(sizeof(int) * (width + 1));
	element[0] = width;
	while (0 < width--)
		element[width + 1] = ft_atoi(sp_arr[width]);
	double_free(sp_arr);
	array = assig_arr(fd, length + 1);
	array[length] = element;
	return (array);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	**array;

	if (!(argc == 1))
	{
		ft_putstr_fd("format error -> ./fdf [name].fdf\n", STDERR_FILENO);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	array = assig_arr(fd, 0);
	close(fd);
	mlx(array);
	int	len = 0;
	while (array[len])
		free(array[len++]);
	free(array);
	return (0);
}
