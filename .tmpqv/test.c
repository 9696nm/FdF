/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:06:24 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/30 16:06:27 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"
#include <string.h>

void	test_free(char *test)
{
	free(test);
	test = NULL;
	return ;
	// printf("%s\n", *test);
}

int	main()
{
	// char	*test;

	// test = malloc(sizeof(char) * 2);
	// *test = 'a';
	// test_free(test);
	// // free(test);
	// test = NULL;
	// // printf("%s\n", test);
	// ft_printf("%s\n", test);
	printf("%f\n", 1-0.5f);
	return (0);
}

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
