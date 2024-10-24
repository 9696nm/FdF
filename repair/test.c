/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:51:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/10/21 21:49:52 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stdio.h>

// static void	ft_putbit(unsigned int num, unsigned long int size)
// {
// 	size *= 8;
// 	while (size--)
// 		ft_putchar_fd((num >> size & 1) + '0', STDOUT_FILENO); //STDOUT_FILENEO
// 	ft_putchar_fd('\n', STDOUT_FILENO);
// }

static void	my_mlx_pixel_put(t_idata *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || SIZE_X <= x || y < 0 || SIZE_Y <= y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	circle(t_idata *img, int d, int x, int y)
{
	int	high;
	int	min;

	high = d / 2;
	min = high - (d - 1);
	for (int i=0; i<d; i++)
	{
		my_mlx_pixel_put(img, min+i+x, min+y, 0xFFFF | d << 16);
		my_mlx_pixel_put(img, min+x, min+i+y, 0xFFFF | d << 16);
		my_mlx_pixel_put(img, min+i+x, high+y, 0xFFFF | d << 16);
		my_mlx_pixel_put(img, high+x, min+i+y, 0xFFFF | d << 16);
	}
}

static void	mlx(void)
{
	t_vars	vars;
	t_idata	img;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIZE_X, SIZE_Y, "Hello world!");
	img.img = mlx_new_image(vars.mlx, SIZE_X, SIZE_Y); 
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
			&img.endian);
	for (int d=0; d<256; d++)
		circle(&img, d, SIZE_X/2, SIZE_Y/2);
	// circle(&img, 10, SIZE_X/2, SIZE_Y/2);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

int	main(void)
{
	mlx();
	return (0);
}
