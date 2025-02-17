/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:49:14 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/17 16:40:05 by hana/hmori       ###   ########.fr       */
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

t_quater	set_quat(float w, float x, float y, float z)
{
	t_quater	q;

	q.w = w;
	q.x = x;
	q.y = y;
	q.z = z;
	return (q);
}

t_crdarr	set_coord_array(int	**array)
{
	int	i;
	t_crdarr	crdarr;
	
	crdarr.arr = array;
	crdarr.width = array[0][0];
	i = 0;
	while (array[i])
		i++;
	crdarr.width = i;
	return (crdarr);
}

t_tarns	reverse_quater(t_quater qv, t_quater p, t_tarns set)
{
	t_quater	res;

	res = quater_rotate(quater_conjugate(qv), p);
	set.x += res.x;
	set.y += res.y;
	set.z += res.z;
	return (set);
}

// t_dsize	displaysize_init(t_xvar *xvar)
// {
// 	t_dsize	dsize;

// 	dsize.width = XDisplayWidth(xvar->display, xvar->screen);
// 	dsize.height = XDisplayHeight(xvar->display, xvar->screen);
// }
