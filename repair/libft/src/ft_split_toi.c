/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_toi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:22:29 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/29 14:17:17 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	section_count(char *str, char c)
{
	int	section_len;

	section_len = 0;
	while (str && *str)
		if (*str == c)
			str++;
		else
		{
			section_len++;
			str = ft_strchr(str, c);
		}
	return (section_len);
}

static int	put_token(char *src, char c, int *res, int token)
{
	char	*endp;

	while (src && *src == c)
		src++;
	res[0] = token;
	if (src && *src)
		endp = ft_strchr(src, c);
	else
		return (0);
	res[token + 1] = ft_atoi(src);
	if (errno == ERANGE)
		return (-1);
	return (put_token(endp, c, res, token + 1));
}

int	*ft_split_toi(char const *src, char c)
{
	int	*res;

	res = malloc(sizeof(int) * (section_count((char *)src, c) + 1));
	if (res == NULL)
		return (NULL);
	if (put_token((char *)src, c, res, 0) == -1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

// int	main(void)
// {
// 	int		i;
// 	int		*res;

// 	res = ft_split_toi(" 9  10 11 1 0fef -s1 -9 -104dwfv    ", ' ');
// 	for (int i=0; i<res[0]; i++)
// 		printf("%d\n", res[i + 1]);
// 	return (0);
// }
