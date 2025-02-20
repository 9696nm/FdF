/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/20 20:05:58 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
// #include "fdf.h"

// Normalisation of quaternions
t_quater	quater_normalize(t_quater q)
{
	float	norm;

	norm = q_rsqrtf(q.w * q.w + q.v.x * q.v.x + q.v.y * q.v.y + q.v.z * q.v.z);
	q.w *= norm;
	q.v.x *= norm;
	q.v.y *= norm;
	q.v.z *= norm;
	return (q);
}

// Product of quaternions
t_quater	quater_multiply(t_quater q1, t_quater q2)
{
	t_quater	result;
	t_vec3		v1;
	t_vec3		v2;

	v1 = q1.v;
	v2 = q2.v;
	result.w = q1.w * q2.w - v1.x * v2.x - v1.y * v2.y - v1.z * v2.z;
	result.v.x = q1.w * v2.x + v1.x * q2.w + v1.y * v2.z - v1.z * v2.y;
	result.v.y = q1.w * v2.y - v1.x * v2.z + v1.y * q2.w + v1.z * v2.x;
	result.v.z = q1.w * v2.z + v1.x * v2.y - v1.y * v2.x + v1.z * q2.w;
	return (result);
}

// Set up conjugate quaternions.
t_quater	quater_conjugate(t_quater q)
{
	t_quater	q_conj;

	q_conj.w = q.w;
	q_conj.v.x = -q.v.x;
	q_conj.v.y = -q.v.y;
	q_conj.v.z = -q.v.z;
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
t_quater	quater_axis_angle(float x, float y, float z, float angle)
{
	float		half_angle;
	float		s;
	t_quater	q;

	half_angle = angle / 2.0f;
	s = sinf(half_angle);
	q.w = cosf(half_angle);
	q.v.x = x * s;
	q.v.y = y * s;
	q.v.z = z * s;
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

// t_vec3	rotate_matrix(float vec_x, float vec_y, float vec_z, t_eanglef ang)
// {
// 	t_vec3	crd;

// 	crd.v.x = rotate_x(rotate_x(vec_x, vec_y, ang.ang_z), vec_z, ang.ang_y);
// 	crd.v.y = rotate_y(vec_z, rotate_y(vec_x, vec_y, ang.ang_z), ang.ang_x);
// 	crd.v.z = rotate_x(rotate_y(vec_x, vec_z, ang.ang_y), vec_y, ang.ang_x);
// 	return (crd);
// }
