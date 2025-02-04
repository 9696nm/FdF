/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/30 12:57:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	rotate_x(float x, float y, float angle)
{
	return (x * cosf(angle * M_PI / 180) - y * sinf(angle * M_PI / 180));
}

float	rotate_y(float x, float y, float angle)
{
	return (x * sinf(angle * M_PI / 180) + y * cosf(angle * M_PI / 180));
}

t_coord	rotate_matrix(float vec_x, float vec_y, float vec_z, t_eanglef ang)
{
	t_coord	crd;

	crd.crd_x = rotate_x(rotate_x(vec_x, vec_y, ang.ang_z), vec_z, ang.ang_y);
	crd.crd_y = rotate_y(vec_z, rotate_y(vec_x, vec_y, ang.ang_z), ang.ang_x);
	crd.depth = rotate_x(rotate_y(vec_x, vec_z, ang.ang_y), vec_y, ang.ang_x);
	return (crd);
}
