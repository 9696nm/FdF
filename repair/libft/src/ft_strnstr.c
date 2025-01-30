/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:11:14 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:22:34 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *source, const char *search, size_t len)
{
	size_t	diff_cou;

	diff_cou = 0;
	if ((source == NULL || search == NULL) && len == 0)
		return (NULL);
	while (*source && len > 0)
	{
		if (!search[diff_cou])
			break ;
		if (source[diff_cou] == search[diff_cou])
			diff_cou++;
		else
		{
			len += diff_cou;
			diff_cou = 0;
			source++;
		}
		len--;
	}
	if (!search[diff_cou])
		return ((char *)source);
	if (!len)
		return (0);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	size_t	any = 0;
// 	char	i[] = "aaabcabcd";
// 	char	j[] = "";
// 	char 	*empty = (char *)"";

// 	printf ("ord : %s\n", strnstr(i, j, any));
// 	// printf ("ft_ : %s\n", ft_strnstr(i, j, any));
// 	return (0);
// }
