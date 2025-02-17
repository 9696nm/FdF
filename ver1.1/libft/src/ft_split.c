/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:25:21 by hmori             #+#    #+#             */
/*   Updated: 2023/09/27 16:25:21 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	section_count(char *str, char c)
{
	int	section_len;

	section_len = 0;
	while (str && *str)
	{
		if (*str == c)
			str++;
		else
		{
			section_len++;
			str = ft_strchr(str, c);
		}
	}
	return (section_len);
}

static int	put_token(char *src, char c, char **res, int token)
{
	char	*endp;

	while (src && *src == c)
		src++;
	res[token] = NULL;
	if (src && *src)
		endp = ft_strchr(src, c);
	else
		return (0);
	if (endp)
		res[token] = ft_substr(src, 0, endp - src);
	else
		res[token] = ft_strdup(src);
	if (res[token] == NULL)
	{
		while (token--)
			free(res[token]);
		return (-1);
	}
	return (put_token(endp, c, res, token + 1));
}

char	**ft_split(char const *src, char c)
{
	char	**res;

	res = malloc(sizeof(char *) * (section_count((char *)src, c) + 1));
	if (res == NULL)
		return (NULL);
	if (put_token((char *)src, c, res, 0) == -1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*src = ",abc,12,,";
// 	char	c = '\0';

// 	char	**res = ft_split(src, c);
// 	if (res)
// 	{
// 		for (int i = 0; res[i]; i++)
// 			printf("%s\n", res[i]);;
// 		for (int i = 0; res[i]; i++)
// 			free(res[i]);
// 		free(res);
// 	}
// 	else
// 		printf("%p\n", res);
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q a.out");
// }

/*
static int	check_clause(const char *src, const char *cstr)
{
	size_t	i;

	i = 0;
	if (!*cstr)
		return (0);
	while (cstr[i])
	{
		if (src[i] != cstr[i])
			return (0);
		i++;
	}
	return (1);
}

static int	count_clause(const char *src, const char *cstr)
{
	int	cl;
	int	flag;
	int	cl_cnt;

	flag = 1;
	cl_cnt = 0;
	while (*src)
	{
		cl = check_clause(src, cstr);
		if (cl)
		{
			flag = 1;
			src += ft_strlen((char *)cstr);
		}
		else if (flag)
		{
			flag = 0;
			cl_cnt++;
		}
		else
			src++;
	}
	return (cl_cnt);
}

static void	put_src(char **res, const char *src, int posi, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		res[posi][i] = src[i];
		i++;
	}
	res[posi][i] = '\0';
}

static int	asg_clause(char **res, const char *src, const char *cstr, int posi)
{
	int		cl;
	size_t	size;

	cl = check_clause(src, cstr);
	if (!*src)
		return (0);
	if (cl)
	{
		asg_clause(res, src += ft_strlen((char *)cstr), cstr, posi);
		return (0);
	}
	size = 0;
	while (*src && !check_clause(src, cstr))
	{
		size++;
		src++;
	}
	res[posi] = (char *)malloc(sizeof(char) * (size + 1));
	if (res[posi] == NULL)
		return (1);
	put_src(res, src - size, posi, size);
	asg_clause(res, src, cstr, posi + 1);
	return (0);
}

char	**ft_split(char const *src, char c)
{
	char	cstr[2];
	int		cl_cnt;
	char	**res;

	cstr[0] = c;
	cstr[1] = '\0';
	if (src == NULL)
		return (NULL);
	cl_cnt = count_clause(src, cstr);
	res = (char **)malloc(sizeof(char *) * (cl_cnt + 1));
	if (res == NULL)
		return (NULL);
	res[cl_cnt] = NULL;
	if (!asg_clause(res, src, cstr, 0))
		return (res);
	while (res)
		free(*res++);
	return (NULL);
}
*/
