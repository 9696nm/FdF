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

#include "fdf.h"

static void	my_mlx_pixel_put(t_idata *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || WIDTH <= x || y < 0 || HEIGHT <= y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

static t_quater	apply_projection(int mx, int my, t_vars *vars)
{
	float		scale;
	t_quater	q;

	q = quater_rotate(vars->rqv,
			arr_off_set(mx, my, vars->varr.arr[my][mx + 1], vars->arrof));
	if (vars->gflag.fl & (1 << TOGGLE_PERSPECTIVE))
	{
		scale = 1.0f / (1.0f + PERSP_FACTER * q.v.z);
		q.v.x *= scale;
		q.v.y *= scale;
	}
	return (q);
}

static int	render_len(int my, t_quater *pr_len, t_idata *newimg, t_vars *vars)
{
	int			mx;
	t_quater	q;
	t_quater	pr_crd;

	if (pr_len == NULL)
		return (1);
	mx = 0;
	while (mx < vars->varr.width)
	{
		q = apply_projection(mx, my, vars);
		if (mx)
			put_line(newimg, crd_off_set(pr_crd.v, vars->param),
				crd_off_set(q.v, vars->param));
		if (my)
			put_line(newimg, crd_off_set(pr_len[mx].v, vars->param),
				crd_off_set(q.v, vars->param));
		pr_crd = q;
		pr_len[mx] = q;
		mx++;
	}
	if (my + 1 < vars->varr.length)
		render_len(my + 1, pr_len, newimg, vars);
	else
		free(pr_len);
	return (0);
}

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
