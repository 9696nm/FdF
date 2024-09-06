/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:19:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/07 02:29:59 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx(void)
{	
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "Hello world!");
	img.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// printf("addr:%zu\npixel:%d\nlen:%d\nendian:%d\n", ft_strlen((char *)mlx), img.bits_per_pixel, img.line_length, img.endian);
	// int	size_per = (100-95);
	// for (int x = (SIZE_X/2)*size_per/100; x<=SIZE_X-((SIZE_X/2)*size_per/100); x++)
	// 	for (int y = (SIZE_Y/2)*size_per/100; y<=SIZE_Y-((SIZE_Y/2)*size_per/100); y++)
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	// my_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	**array;

	if (argc < 2)
	{
		ft_putstr_fd("format error -> ./fdf [name].fdf\n", STDERR_FILENO);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	for (char *a_row; a_row = get_next_line(fd); a_row)
	{
		array = ft_split(a_row, ' ');
		free(a_row);
		for (int i=0; *array[i] != '\n'; i++)
			printf("%d:%s\n", i, array[i]);
		for (int i=0; array[i]; i++)
			free(array[i]);
		free(array);
	}
	close(fd);
	return (0);
}
