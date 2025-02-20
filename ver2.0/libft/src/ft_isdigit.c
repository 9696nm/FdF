/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:45:05 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:19:43 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int num)
{
	return ('0' <= num && num <= '9');
}

/*ifに入った時のreturnはnumでも1でもよき（\0を検出するための1？でもうまくいかないような）*/

// #include <stdio.h>
// #include <ctype.h>
// #include <limits.h>

// int	main(void)
// {
// 	for (int i = 0; i < 200; i++)
// 	{
// 		if (ft_isdigit(i))
// 			printf("%c (%d)\n", i, i);
// 	}
// 	return (0);
// }
