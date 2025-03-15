/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:12:45 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/20 23:12:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parameter_init(t_vars *vars)
{
	vars->rqv = quater_normalize(quater_axis_angle
			(DEF_VIEW_X, DEF_VIEW_Y, DEF_VIEW_Z, DEF_VIEW_AXIS * M_PI / 180));
	vars->qv = vars->rqv;
	vars->arrof = arr_off_init(vars->varr.arr);
	vars->param.zoom = DEF_ZOOM;
	vars->gflag.fl = (1 << RE_GRAPHIC) | (0 << MOUSE_PRESS)
		| (0 << TOGGLE_PERSPECTIVE);
}

t_arrof	crd_off_move(t_quater rqv, t_arrof set, t_vec3 move)
{
	t_quater	p;

	p.w = 0;
	p.v = (t_vec3){set.x, set.y, set.z};
	p = quater_rotate(rqv, p);
	p.v.x += move.x;
	p.v.y += move.y;
	p.v.z += move.z;
	p = quater_rotate(quater_conjugate(rqv), p);
	set.x = p.v.x;
	set.y = p.v.y;
	set.z = p.v.z;
	return (set);
}
