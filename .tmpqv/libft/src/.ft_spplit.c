/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:21:38 by hmori             #+#    #+#             */
/*   Updated: 2023/10/14 22:21:38 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_spplit(char const *src, char *cstr)
{
	int		cl_cnt;
	char	**res;

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
