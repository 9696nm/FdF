/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:15:28 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	size;
	size_t	count;

	if (s == NULL || f == NULL)
		return ;
	size = ft_strlen(s);
	count = 0;
	while (count < size)
	{
		f((unsigned int)count, s + count);
		count++;
	}
}

// static char buf[100] = {};
// static void tobuf(unsigned int i, char *str) {
//     static size_t   idx = 0;
//     (void)i;

//     buf[idx++] = *str;
// }

/*test case*/

// void	iter(unsigned int i, char *s)
// {
// 	*s += i;
// }

// void	low(unsigned int i, char *c)
// {
// 	if ('A' <= c[i] && c[i] <= 'Z')
// 		c[i] = c[i] + ('a' - 'A');
// }

// void	high(unsigned int i, char *c)
// {
// 	if ('a' <= c[i] && c[i] <= 'z')
// 		c[i] = c[i] + ('A' - 'a');
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	text[] = "hello";
// 	void	(*list[2])(unsigned int, char *);

// 	// list[0] = &low;
// 	// list[1] = &high;
// 	// ft_striteri(text, iter);
// 	ft_striteri(text, tobuf);
// 	printf ("%s$\n", buf);
// 	return (0);
// }
