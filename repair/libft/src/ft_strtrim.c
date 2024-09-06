/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:07:35 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check(unsigned char c, unsigned char *set)
{
	while (set[0])
	{
		if (c == set[0])
			return (1);
		set++;
	}
	return (0);
}

static void	make_point(size_t *point, unsigned char *s1, unsigned char *set)
{
	size_t	s1_len;

	s1_len = ft_strlen((char *)s1);
	point[0] = 0;
	point[1] = (s1_len - 1);
	while (check(s1[point[0]], set) && point[0] < s1_len)
		point[0]++;
	while (check(s1[point[1]], set) && point[1] > point[0])
		point[1]--;
	point[1] = point[1] - point[0] + 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			point[2];
	unsigned char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	make_point(point, (unsigned char *)s1, (unsigned char *)set);
	result = (unsigned char *)malloc(sizeof(unsigned char) * point[1] + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	result[point[1]] = '\0';
	while (i < point[1])
	{
		result[i] = s1[point[0] + i];
		i++;
	}
	return ((char *)result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		point[2];
// 	char	ord[] = "bcd";
// 	char	set[] = "";
// 	char	*res;

// 	make_point(point, ord, set);
// 	for (int i = 0; i < 2; i++)
// 		printf("%d\n", point[i]);
// 	res = ft_strtrim(ord, set);
// 	printf ("%s\n%s\n", ord, res);
// 	free (res);
// 	return (0);
// }
