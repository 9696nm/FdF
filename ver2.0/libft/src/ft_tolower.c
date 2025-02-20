/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:57:12 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:22:47 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int num)
{
	if ('A' <= num && num <= 'Z')
		return (num + ('a' - 'A'));
	return (num);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	set[4] = {'B', 86, 'r', ','};

// 	for (int i = 0; i < 4; i++)
// 		printf("%c\n", ft_tolower(set[i]));
// 	return (0);
// }
