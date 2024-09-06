/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:41 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_toupper(int num)
{
	if ('a' <= num && num <= 'z')
		return (num + ('A' - 'a'));
	return (num);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	set[4] = {'B', 86, 'r', ','};

// 	for (int i = 0; i < 4; i++)
// 		printf("%c\n", ft_toupper(set[i]));
// 	return (0);
// }
