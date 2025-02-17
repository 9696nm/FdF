/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:01:02 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:19:30 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int num)
{
	return (ft_isdigit(num) || ft_isalpha(num));
}

/*returnについてはdigit参照*/

// #include <stdio.h>
// #include <ctype.h>
// #include <limits.h>

// int	main(void)
// {
// 	for (int i = 0; i < UCHAR_MAX + 1; i++)
// 	{
// 		if (ft_isalnum(i))
// 			printf("%c (%d)\n", i, i);
// 	}
// 	return (0);
// }
