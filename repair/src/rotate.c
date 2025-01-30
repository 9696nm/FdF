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

float	rotate_x(float x, float y, float theta)
{
	return (x * cos(theta * M_PI / 180) - y * sin(theta * M_PI / 180));
}

float	rotate_y(float x, float y, float theta)
{
	return (x * sin(theta * M_PI / 180) + y * cos(theta * M_PI / 180));
}
