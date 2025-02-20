/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sprt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:26:34 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/30 16:06:41 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "q_sqrt.h"

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

float	q_rsqrt_ori(float number)
{
	float		x2;
	t_cast		cast;
	const float	threehalfs = 1.5F;

	x2 = number * 0.5F;
	cast.f = number;
	cast.li = 0x5f3759df - (cast.li >> 1);
	cast.f = cast.f * (threehalfs - (x2 * cast.f * cast.f));
	return (cast.f);
}

#include "fdf.h"
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("1/sqrtf :%f\n", 1/sqrtf(atoi(argv[1])));
	printf("qrsqrt o:%f\n", q_rsqrt_ori(atoi(argv[1])));
	printf("qrsqrt c:%f\n", q_rsqrtf(atoi(argv[1])));
	return (0);
}
