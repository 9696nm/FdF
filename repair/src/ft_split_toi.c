/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_toi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:22:29 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/07 15:10:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	section_count(char *str, char c)
{
	int	section_len;

	section_len = 1;
	while (*str)
		if (*str++ == c)
			section_len++;
	return (section_len);
}

#include <stdio.h>

static int	put_token(char *src, char c, int *res, int token)
{
	char	*endp;

	endp = ft_strchr(src, c);
	printf("%s\n", endp);
	if (endp)
		src[endp - src] = '\0';
	res[token] = ft_atoi(src);
	if (endp && *endp)
		return (put_token(endp + 1, c, res, token + 1));
	return (0);
}

int	*ft_split_toi(char const *src, char c)
{
	int	*res;

	res = malloc(sizeof(int) * (section_count((char *)src, c)));
	if (res == NULL)
		return (NULL);
	put_token((char *)src, c, res, 0);
	return (res);
}

int	main(void)
{
	int		i;
	int		*res;

	res = ft_split_toi("9 10 11 1 0 -1 -9 -10 ", ' ');
	i = sizeof(res) / sizeof(*res);
	while (i--);
		printf("%d\n", res[i]);
	return (0);
}
