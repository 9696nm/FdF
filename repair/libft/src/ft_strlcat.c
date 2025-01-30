/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:05:38 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:22:16 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count_dst;
	size_t	count_src;

	count_src = 0;
	if (dstsize)
	{
		count_dst = ft_strlen(dst);
		while (src[count_src] && (count_dst + count_src) + 1 < dstsize)
		{
			dst[count_dst + count_src] = src[count_src];
			count_src++;
		}
		dst[count_dst + count_src] = '\0';
	}
	while (src[count_src])
		count_src++;
	if (count_dst > dstsize)
		return (count_src + dstsize);
	return (count_dst + count_src);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	size_t	dstsize = 0;

// 	// char	dest1[] = "AX";
// 	// char	dest2[] = "AX";
// 	char	*dest1 = NULL;
// 	char	*dest2 = NULL;
// 	char	src[] = "b";

// 	printf("return : %lu\n", strlcat(dest1, src, dstsize));
// 	for (int i = 0; i < dstsize; i++)
// 		printf("%#x\n", dest1[i]);
// 	printf ("\n");
// 	printf("return : %lu\n", ft_strlcat(dest2, src, dstsize));
// 	for (int i = 0; i < dstsize; i++)
// 		printf("%#x\n", dest2[i]);
// 	return (0);
// }
