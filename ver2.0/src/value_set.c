/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:49:14 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/20 20:05:55 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_varr	crdarr_init(int **array)
{
	int		i;
	t_varr	varr;

	varr.arr = array;
	varr.width = array[0][0];
	i = 0;
	while (array[i])
		i++;
	varr.length = i;
	return (varr);
}

t_arrof	arr_off_init(int **mat_arr)
{
	int		len;
	t_arrof	arrof;

	len = 0;
	while (mat_arr[len])
		len++;
	arrof.x = (float)mat_arr[0][0] / 2;
	arrof.y = (float)len / 2;
	arrof.z = 0;
	arrof.z_elast = Z_ELASTICITY;
	return (arrof);
}

t_quater	arr_off_set(int mx, int my, int mz, t_arrof arrof)
{
	t_quater	p;
	t_vec3		vec;

	vec.x = mx - arrof.x;
	vec.y = my - arrof.y;
	vec.z = (0 - mz) * arrof.z_elast - arrof.z;
	p.w = 0;
	p.v = vec;
	return (p);
}

t_vec3	crd_off_set(t_vec3 v, t_param param)
{
	t_vec3	crd;

	crd.x = v.x * param.zoom + WIDTH / 2;
	crd.y = v.y * param.zoom + HEIGHT / 2;
	crd.z = v.z;
	return (crd);
}
