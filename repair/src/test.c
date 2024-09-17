/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:19:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/16 22:28:04 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

static double rotate_x(double x, double y, int axis)
{
	return ((x)*cos(axis*M_PI/180)-(y)*sin(axis*M_PI/180));
}

static double rotate_y(double x, double y, int axis)
{
	return ((x)*sin(axis*M_PI/180)+(y)*cos(axis*M_PI/180));
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || SIZE_X <= x || y < 0 || SIZE_Y <= y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
 }

static void	mlx(int x_axis, int y_axis, int z_axis, int **array)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int zoom = 50;
	int	or_x = 5;
	int	or_y = 5;
	double	or_z = 0.3;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "Hello world!");
	img.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// printf("addr:%zu\npixel:%d\nlen:%d\nendian:%d\n", ft_strlen((char *)mlx), img.bits_per_pixel, img.line_length, img.endian);
	for (int ly=0; array[ly]; ly++)
		for (int lx=0; lx<array[ly][0]; lx++)
		{
			my_mlx_pixel_put(&img, (int)(rotate_x(rotate_x(lx-or_x, ly-or_y, z_axis), array[ly][lx+1]*or_z, y_axis)*zoom+SIZE_X/2),
				(int)(rotate_x(rotate_y(lx-or_x, ly-or_y, z_axis), array[ly][lx+1]*or_z, x_axis)*zoom+SIZE_Y/2), 0x00FFF000);
		}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
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

	len = 0;
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

	if (argc < 2)
	{
		ft_putstr_fd("format error -> ./fdf [name].fdf\n", STDERR_FILENO);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	array = assig_arr(fd, 0);
	close(fd);
	mlx(0, 0, 30, array);
	int	len = 0;
	while (array[len])
		free(array[len++]);
	free(array);
	return (0);
}
