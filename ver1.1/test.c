/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:06:24 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/17 14:42:28 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	test2(void *a)
{
	free(a);
}

void	test(void *a)
{
	test2(a);
}

int	main()
{
	test(malloc(1));
	return (0);
}

// int main()
// {
// 	int		len = 50;
// 	size_t	size = sizeof(t_coord) * 10;
// 	clock_t	start_time;
// 	clock_t	end_time;
// 	double	elapsed_time;

// 	printf("len: %d\n", len);

// 	start_time = clock();
// 	t_coord*	ptr = (t_coord *)malloc(size);
// 	for (int i = 0; i < len; i++)
// 	{
// 		ptr[i].crd_x = 100000;
// 		ptr[i].crd_y = 100000;
// 		ptr[i].depth = 100000;
// 	}
// 	free(ptr);
// 	end_time = clock();
// 	elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
// 	printf("file size (byte): %zu\n", size);
// 	printf("Time taken for malloc: %f seconds\n", elapsed_time);
	
// 	start_time = clock();
// 	for (int i = 0; i < len; i++)
// 		quater_rotate(set_quat(5, 5, 5, 5), set_quat(5, 5, 5, 5));
// 	end_time = clock();
// 	elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
// 	printf("Time taken for malloc: %f seconds\n", elapsed_time);
// 	return (0);
// }

// int	main()
// {
// 	float		test;
// 	uint32_t	cast;

// 	cast = (0b1) << 31; //sing
// 	cast = cast | (0b01111111) << 23; //index
// 	cast = cast | (0b0000000) << 16; //fraction
// 	cast = cast | (0b00000000) << 8;
// 	cast = cast | (0b00000000) << 0;
// 	memcpy(&test, &cast, sizeof(cast));
// 	printf("%f\n", test);
// 	return (0);
// }
