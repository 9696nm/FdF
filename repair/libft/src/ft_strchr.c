/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:25:57 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *source, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*source)
	{
		if (*source == uc)
			return ((char *)source);
		source++;
	}
	if (uc == '\0')
		return ((char *)source);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int		c = '\0';
// 	char	test[] = "scsaafb rgr", *p, *q;

// 	char	s[] = "tripouille";

// 	// p = strchr(test, c);
// 	q = ft_strchr(s, 't' + 256);
// 	printf("source : %s\nft_ : %s\n", s, q);
// 	return (0);
// }
