/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:02:48 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			size;
	unsigned char	*src;
	unsigned char	*copy;

	src = (unsigned char *)s1;
	size = ft_strlen((char *)src);
	copy = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (copy == NULL)
		return (NULL);
	copy[size] = '\0';
	while (size-- > 0)
		copy[size] = s1[size];
	return ((char *)copy);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	test[] = "01123";
// 	char	*result;

// 	result = ft_strdup(test);
// 	printf ("%s\n", result);
// 	free (result);
// 	return (0);
// }
