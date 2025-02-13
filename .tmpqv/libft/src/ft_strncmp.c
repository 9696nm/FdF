/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:47:02 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:22:30 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (c1[i] && c2[i])
	{
		if (c1[i] - c2[i] || !(i + 1 < n))
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	size_t	any_cmp = 50;
// 	char	*s1 = "0123", *s2 = "0124";

// 	printf("s1 : %s\ns2 : %s\nord_diff : %d\nft__diff : %d\n",
//  s1, s2, strncmp(s1, s2, any_cmp), ft_strncmp(s1, s2, any_cmp));
// 	return (0);
// }
