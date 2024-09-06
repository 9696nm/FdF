/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:23:37 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			size1;
	size_t			size2;
	unsigned char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	result = (unsigned char *)malloc
		(sizeof(unsigned char) * (size1 + size2 + 1));
	if (result == NULL)
		return (NULL);
	result[size1 + size2] = '\0';
	while (size2--)
		result[size1 + size2] = ((unsigned char *)s2)[size2];
	while (size1--)
		result[size1] = ((unsigned char *)s1)[size1];
	return ((char *)result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	test1[] = "012";
// 	char	test2[] = "45";

// 	printf ("before : %s, %s\n", test1, test2);
// 	printf ("after : %s\n", ft_strjoin(test1, test2));
// 	return (0);
// }
