/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:32:42 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*source1;
	unsigned char	*source2;

	source1 = (unsigned char *)s1;
	source2 = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (source1[count] - source2[count])
			return (source1[count] - source2[count]);
		count++;
	}
	return (0);
}

// #include <string.h>

// int	main(void)
// {
// 	int		i, j;
// 	size_t	n = 4;
// 	char	s[] = {-128, 0, 127, 0};
// 	char	sCpy[] = {-128, 0, 127, 0};
// 	char	s2[] = {0, 0, 127, 0};
// 	char	s3[] = {0, 0, 42, 0};

// 	// i = memcmp(s1, s2, n);
// 	j = ft_memcmp(s, sCpy, n);
// 	printf ("return : %d\n", j);
// 	return (0);
// }
