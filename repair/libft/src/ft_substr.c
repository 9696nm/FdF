/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:26:12 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			size;
	unsigned char	*result;

	size = 0;
	if (s == NULL)
		return (NULL);
	if (len && start < (unsigned int)ft_strlen((char *)s) + 1)
	{
		while (s[start + size] && size < len)
			size++;
	}
	result = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	while (size-- > 0)
		result[size] = ((unsigned char *)s)[start + size];
	return ((char *)result);
}

/*
s -> '\0'の場合は1枠確保して"\0" を返す
s -> NULLの場合はNULLを返す 
*/

// #include <stdio.h>

// int	main(void)
// {
// 	char	ord[] = "0123456";
// 	char	*res;

// 	res = ft_substr("\0", 0, 11);
// 	printf ("%s\n", res);
// 	free (res);
// 	return (0);
// }
