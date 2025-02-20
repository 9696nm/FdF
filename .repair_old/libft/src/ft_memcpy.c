/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:07:54 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:20:48 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*ch_buf1;
	unsigned char	*ch_buf2;

	ch_buf1 = (unsigned char *)buf1;
	ch_buf2 = (unsigned char *)buf2;
	if (ch_buf1 == NULL && ch_buf2 == NULL)
		return (NULL);
	while (n-- > 0)
		ch_buf1[n] = ch_buf2[n];
	return (ch_buf1);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s1[7] = {1, 1, 1, 1, 1, 1, 1};
// 	char	s2[7] = {"123\0xyz"};

// 	ft_memcpy(NULL, NULL, 3);
// 	for (int i = 0; i < 7; i++)
// 		printf("%#x\n", s1[i]);
// 	return (0);
// }

/*
オーバー分は未定義で良い
*/
