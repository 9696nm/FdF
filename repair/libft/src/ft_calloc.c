/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:31:51 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	mal_size;
	char	*result;

	if (n == 0 || size == 0)
		mal_size = 1;
	else
	{
		if (n > SIZE_MAX / size)
			return (NULL);
		mal_size = n * size;
	}
	result = (void *)malloc(mal_size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, mal_size);
	return ((void *)result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*test1;
// 	char	*test2;

// 	test1 = (char *)calloc(SIZE_MAX, SIZE_MAX);
// 	test2 = (char *)ft_calloc(SIZE_MAX / 4, 4);
// 	printf ("%p\n", test1);
// 	printf ("%p\n", test2);
// 	free (test1);
// 	free (test2);
// 	return (0);
// }
