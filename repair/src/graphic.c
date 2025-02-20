/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:32:12 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/20 20:05:40 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
// #include "fdf.h"

void	parameter_init(t_vars *vars)
{
	vars->rqv = quater_normalize(quater_axis_angle
			(DEF_VIEW_X, DEF_VIEW_Y, DEF_VIEW_Z, DEF_VIEW_AXIS * M_PI / 180));
	vars->qv = vars->rqv;
	vars->arrof = arr_off_init(vars->varr.arr);
	vars->param.zoom = DEF_ZOOM;
	vars->gflag.fl = (1 << RE_GRAPHIC) | (0 << MOUSE_PRESS);
}

static void	my_mlx_pixel_put(t_idata *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || WIDTH <= x || y < 0 || HEIGHT <= y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// bresenham line
static void	put_line(t_idata *idata, t_vec3 q1, t_vec3 q2)
{
	int		steps;
	float	dx;
	float	dy;

	dx = q2.x - q1.x;
	dy = q2.y - q1.y;
	steps = fabs(dx);
	if (steps < fabs(dy))
		steps = fabs(dy);
	dx = dx / steps;
	dy = dy / steps;
	while (steps--)
	{
		my_mlx_pixel_put(idata, roundf(q1.x), roundf(q1.y), 0xFFFFFFFF);
		q1.x += dx;
		q1.y += dy;
	}
}

static int	render_len(int my, t_quater *pr_len, t_idata *newimg, t_vars *vars)
{
	int			mx;
	t_quater	q;
	t_quater	pr_crd;

	if (pr_len == NULL)
		return (1);
	mx = -1;
	while (++mx < vars->varr.width)
	{
		q = quater_rotate(vars->rqv,
				arr_off_set(mx, my, vars->varr.arr[my][mx + 1], vars->arrof));
		if (mx)
			put_line(newimg, crd_off_set(pr_crd.v, vars->param),
				crd_off_set(q.v, vars->param));
		if (my)
			put_line(newimg, crd_off_set(pr_len[mx].v, vars->param),
				crd_off_set(q.v, vars->param));
		pr_crd = q;
		pr_len[mx] = q;
	}
	if (my + 1 < vars->varr.length)
		render_len(my + 1, pr_len, newimg, vars);
	else
		free(pr_len);
	return (0);
}

		// t_vec3 test = crd_off_set(q.v, vars->param);
		// my_mlx_pixel_put(newimg, test.x, test.y, 0xFFFFFFFF);

int	render_frame(t_vars *vars)
{
	t_idata	newimg;

	if (vars->gflag.fl & (1 << RE_GRAPHIC))
	{
		vars->gflag.fl &= ~(1 << RE_GRAPHIC);
		newimg.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
		newimg.addr = mlx_get_data_addr(newimg.img, &newimg.bits_per_pixel,
				&newimg.size_line, &newimg.endian);
		render_len(0, malloc(sizeof(t_quater) * vars->varr.width),
			&newimg, vars);
		mlx_put_image_to_window(vars->mlx, vars->win, newimg.img, 0, 0);
		mlx_destroy_image(vars->mlx, vars->idata.img);
		vars->idata = newimg;
	}
	return (0);
}


// #include <time.h>
// #include <stdio.h>

// int	render_frame(t_vars *vars)
// {
// 	t_idata	newimg;

// 	clock_t	start_time;
// 	clock_t	end_time;

// 	if (vars->gflag.fl & (1 << RE_GRAPHIC))
// 	{
// 		vars->gflag.fl &= ~(1 << RE_GRAPHIC);
// 		newimg.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
// 		newimg.addr = mlx_get_data_addr(newimg.img, &newimg.bits_per_pixel,
// 				&newimg.size_line, &newimg.endian);

// 		start_time = clock();
// 		render_len(0, malloc(sizeof(t_quater) * vars->varr.width), &newimg, vars);
// 		end_time = clock();
// 		printf("Time taken for malloc: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

// 		mlx_put_image_to_window(vars->mlx, vars->win, newimg.img, 0, 0);
// 		mlx_destroy_image(vars->mlx, vars->idata.img);
// 		vars->idata = newimg;
// 	}
// 	return (0);
// }


// static t_quater	render_len(int mx, int my, t_idata *newimg, t_vars *vars)
// {
// 	t_quater	q;
// 	t_quater	next;

// 	q = quater_rotate(vars->rqv,
// 			arr_off_set(mx, my, vars->varr.arr[my][mx + 1], vars->arrof));
// 	if (mx + 1 < vars->varr.arr[my][0])
// 	{
// 		next = render_len(mx + 1, my, newimg, vars);
// 		put_line(newimg, crd_off_set(next.v, vars->param),
// 			crd_off_set(q.v, vars->param));
// 	}
// 	if (vars->varr.arr[my + 1])
// 	{
// 		next = quater_rotate(vars->rqv,
// 			arr_off_set(mx, my + 1, vars->varr.arr[my + 1][mx + 1], vars->arrof));
// 		put_line(newimg, crd_off_set(next.v, vars->param),
// 			crd_off_set(q.v, vars->param));
// 	}
// 	return (q);
// }

// #include <time.h>
// #include <stdio.h>

// int	render_frame(t_vars *vars)
// {
// 	int			len;
// 	t_idata		newimg;

// 	clock_t	start_time;
// 	clock_t	end_time;

// 	if (vars->gflag.fl & (1 << RE_GRAPHIC))
// 	{
// 		vars->gflag.fl &= ~(1 << RE_GRAPHIC);
// 		newimg.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
// 		newimg.addr = mlx_get_data_addr(newimg.img, &newimg.bits_per_pixel,
// 				&newimg.size_line, &newimg.endian);

// 		start_time = clock();
// 		len = 0;
// 		while (vars->varr.arr[len])
// 			render_len(0, len++, &newimg, vars);
// 		end_time = clock();
// 		printf("Time taken for malloc: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

// 		mlx_put_image_to_window(vars->mlx, vars->win, newimg.img, 0, 0);
// 		mlx_destroy_image(vars->mlx, vars->idata.img);
// 		vars->idata = newimg;
// 	}
// 	return (0);
// }
