/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:49:14 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/30 22:49:15 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tarns	set_trans(int **mat_arr)
{
	int		len;
	t_tarns	origin;

	len = 0;
	while (mat_arr[len])
		len++;
	origin.x = (float)mat_arr[0][0] / 2;
	origin.y = (float)len / 2;
	origin.z = 0;
	return (origin);
}

t_coord	set_coord(int crd_x, int crd_y, int depth)
{
	t_coord	crd;

	crd.crd_x = crd_x;
	crd.crd_y = crd_y;
	crd.depth = depth;
	return (crd);
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

// static t_quater	set_quater(float w, float x, float y, float z)
// {
// 	t_quater	q;

// 	q.w = w;
// 	q.x = x;
// 	q.y = y;
// 	q.z = z;
// 	return (q);
// }

// t_dsize	displaysize_init(t_xvar *xvar)
// {
// 	t_dsize	dsize;

// 	dsize.width = XDisplayWidth(xvar->display, xvar->screen);
// 	dsize.height = XDisplayHeight(xvar->display, xvar->screen);
// }
