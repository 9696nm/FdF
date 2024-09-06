/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:03:43 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalpha(int num)
{
	return (('a' <= num && num <= 'z') || ('A' <= num && num <= 'Z'));
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	set[4] = {'A', 65, 'a', '\n'};

// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (isalpha(set[i]))
// 			printf("nm %d, Yes\n", set[i]);
// 		else
// 			printf("nm %d, No\n", set[i]);
// 		if (ft_isalpha(set[i]))
// 			printf("ft %d, Yes\n", set[i]);
// 		else
// 			printf("ft %d, No\n", set[i]);
// 		printf("\n");
// 	}
// 	return (0);
// }
