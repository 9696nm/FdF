/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:25:38 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:22:27 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size;
	unsigned char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen((char *)s);
	result = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	while (size-- > 0)
		result[size] = (unsigned char)f((unsigned int)size, s[size]);
	return ((char *)result);
}

/*
char addOne(unsigned int i, char c) {return (i + c);}
*/

/*test case*/
// char	high(unsigned int i, char c)
// {
// 	if ('a' <= c && c <= 'z')
// 		return ((char)(c + ('A' - 'a')));
// 	return (c);
// }

// char	low(unsigned int i, char c)
// {
// 	if ('A' <= c && c <= 'Z')
// 		return ((char)(c + ('a' - 'A')));
// 	return (c);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	before[] = "";
// 	char	*after;
// 	char	(*list[3])(unsigned int, char);

// 	list[0] = &high;
// 	list[1] = &low;
// 	list[2] = NULL;
// 	printf ("orid : %s\n", before);
// 	for (int i = 0; list[i]; i++)
// 	{
// 		after = ft_strmapi(before, list[i]);
// 		printf ("%d : %s\n", i, after);
// 		free (after);
// 	}
// /*
// 	after = ft_strmapi("", addOne);
// 	printf ("%s\n", after);
// 	free (after);
// */
// 	return (0);
// }
