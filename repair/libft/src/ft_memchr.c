/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:07 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:20:42 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;

	source = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*source == (unsigned char)c)
			return (source);
		source++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	size_t	any_long = 3;
// 	int		c = '1';
// 	char	test[] = {'a', '2', '1', '\0'}, *p ,*q;

// 	p = memchr(test, c, any_long);
// 	q = ft_memchr(test, c, any_long);
// 	printf ("ord : %s\nft_ : %s\n", p, q);
// 	return (0);
// }
