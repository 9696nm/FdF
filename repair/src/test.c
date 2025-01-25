/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:51:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/24 15:40:32 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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

void	drawCircleTest(t_idata *img, int centerX, int centerY, int radius, int color)
{
	
}

void drawCircle(t_idata *img, int centerX, int centerY, int radius, int color) {
	int x = radius;
	int y = 0;
	int p = 1 - radius;
	int	halfcolor = ((color>>16&0xFF)/2)<<16|((color>>8&0xFF)/2)<<8|(color&0xFF)/2;
	int	i;

	while (y <= x)
	{
		my_mlx_pixel_put(img, centerX + x, centerY + y, halfcolor);
		my_mlx_pixel_put(img, centerX + y, centerY + x, halfcolor);
		my_mlx_pixel_put(img, centerX - y, centerY + x, halfcolor);
		my_mlx_pixel_put(img, centerX - x, centerY + y, halfcolor);
		my_mlx_pixel_put(img, centerX - x, centerY - y, halfcolor);
		my_mlx_pixel_put(img, centerX - y, centerY - x, halfcolor);
		my_mlx_pixel_put(img, centerX + y, centerY - x, halfcolor);
		my_mlx_pixel_put(img, centerX + x, centerY - y, halfcolor);
		
		i = x;
		while (0 < i--)
		{
			my_mlx_pixel_put(img, centerX + i, centerY + y, color);
			my_mlx_pixel_put(img, centerX - i, centerY + y, color);
			my_mlx_pixel_put(img, centerX + i, centerY - y, color);
			my_mlx_pixel_put(img, centerX - i, centerY - y, color);
		}
		
		y++;
		if (p <= 0)
			p += 2 * y + 1;
		else
		{
			x--;

			i = y;
			while (0 < i--)
			{
				my_mlx_pixel_put(img, centerX + i, centerY + x, color);
				my_mlx_pixel_put(img, centerX - i, centerY + x, color);
				my_mlx_pixel_put(img, centerX + i, centerY - x, color);
				my_mlx_pixel_put(img, centerX - i, centerY - x, color);
			}
			p += 2 * (y - x) + 1;
		}
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
	// for (int d=0; d<256; d++)
	// 	circle(&img, d, SIZE_X/2, SIZE_Y/2);
	// circle(&img, 10, SIZE_X/2, SIZE_Y/2);
	// drawCircle(&img, 640, 360, 150, 0x40FF40);
	drawCircle(&img, 235, 250, 0, 0xFFFFFF);
	drawCircle(&img, 240, 250, 1, 0xFFFFFF);
	drawCircle(&img, 245, 250, 2, 0xFFFFFF);
	drawCircle(&img, 255, 250, 3, 0xFFFFFF);
	drawCircle(&img, 270, 250, 4, 0xFFFFFF);
	drawCircle(&img, 300, 250, 10, 0xFFFFFF);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

int	main(void)
{
	mlx();
	return (0);
}
