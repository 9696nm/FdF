/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rsqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:26:34 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/20 20:05:33 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "q_rsqrt.h"

float	q_rsqrtf(float number)
{
	float		x2;
	t_cast		cast;
	const float	threehalfs = 1.5F;

	cast.li = 0;
	x2 = number * 0.5F;
	cast.f = number;
	cast.li = 0x5f37bcb6 - (cast.li >> 1);
	cast.f = cast.f * (threehalfs - (x2 * cast.f * cast.f));
	return (cast.f);
}
