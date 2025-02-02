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
	return (x * cosf(angle * M_PI / 180) - y * sin(angle * M_PI / 180));
}

float	rotate_y(float x, float y, float angle)
{
	return (x * sinf(angle * M_PI / 180) + y * cos(angle * M_PI / 180));
} 
