/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/13 21:40:39 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Normalisation of quaternions
t_quater	quater_normalize(t_quater q)
{
	float	norm;

	norm = 1 / sqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
	q.w *= norm;
	q.x *= norm;
	q.y *= norm;
	q.z *= norm;
	return (q);
}

// product of quaternions
t_quater	quater_multiply(t_quater q1, t_quater q2)
{
	t_quater	result;

	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return (result);
}

// Set up conjugate quaternions.
t_quater	quater_conjugate(t_quater q)
{
	t_quater	q_conj;

	q_conj.w = q.w;
	q_conj.x = -q.x;
	q_conj.y = -q.y;
	q_conj.z = -q.z;
	return (q_conj);
}

// Rotation of 3D vectors by quaternions
t_quater	quater_rotate(t_quater qv, t_quater p)
{
	t_quater	q_conj;
	t_quater	result;

	q_conj = quater_conjugate(qv);
	result = quater_multiply(quater_multiply(qv, p), q_conj);
	return (result);
}

// Quaternions from axes and angles.
t_quater	quaternion_axis_angle(float x, float y, float z, float angle)
{
	float		half_angle;
	float		s;
	t_quater	q;

	half_angle = angle / 2.0f;
	s = sin(half_angle);
	q.w = cos(half_angle);
	q.x = x * s;
	q.y = y * s;
	q.z = z * s;
	return (q);
}

// float	rotate_x(float x, float y, float angle)
// {
// 	return (x * cosf(angle * M_PI / 180) - y * sinf(angle * M_PI / 180));
// }

// float	rotate_y(float x, float y, float angle)
// {
// 	return (x * sinf(angle * M_PI / 180) + y * cosf(angle * M_PI / 180));
// }

// t_coord	rotate_matrix(float vec_x, float vec_y, float vec_z, t_eanglef ang)
// {
// 	t_coord	crd;

// 	crd.crd_x = rotate_x(rotate_x(vec_x, vec_y, ang.ang_z), vec_z, ang.ang_y);
// 	crd.crd_y = rotate_y(vec_z, rotate_y(vec_x, vec_y, ang.ang_z), ang.ang_x);
// 	crd.depth = rotate_x(rotate_y(vec_x, vec_z, ang.ang_y), vec_y, ang.ang_x);
// 	return (crd);
// }
