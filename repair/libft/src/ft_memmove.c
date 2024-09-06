/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:07:36 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	forword(unsigned char *ch_dest, unsigned char *ch_src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		ch_dest[i] = ch_src[i];
		i++;
	}
}

static void	revers(unsigned char *ch_dest, unsigned char *ch_src, size_t n)
{
	while (n-- > 0)
		ch_dest[n] = ch_src[n];
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ch_dest;
	unsigned char	*ch_src;

	ch_dest = (unsigned char *)dest;
	ch_src = (unsigned char *)src;
	if (!ch_dest && !ch_src)
		return (ch_dest);
	if (ch_dest > ch_src && ch_dest < ch_src + n)
		revers(ch_dest, ch_src, n);
	else
		forword(ch_dest, ch_src, n);
	return (ch_dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	// char	s1[7] = {1, 1, 1, 1, 1, 1, 1};
// 	// char	s2[7] = {"123\0xyz"};
// 	char *src = malloc(10);
// 	for (int i = 0; i < 10; i++)
// 		src[i] = i;
// 	char *dst = malloc(10);

// 	ft_memmove(dst, dst + 3, 8);
// 	for (int i = 0; i < 8; i++)
// 		printf("%#x\n", dst[i]);
// 	return (0);
// }

// /*
// destとsrcが同じものであった時にも正しく動かないといけない
// */
