/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:58:28 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/23 16:34:48 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <stdio.h>

void test(t_point *point)
{
	point->x = 10;
	// t_point	*point;

	// point = malloc(sizeof(t_point) * (3 + 1));
	// point[2].x = 10;
	// return (point);
}

int	main(void)
{
	// t_point	point;

	// test(&point);
	printf("%f\n", sqrt(4));
	// free(point);
	return (0);
}
