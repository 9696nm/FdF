/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:58:22 by hmori             #+#    #+#             */
/*   Updated: 2024/09/07 01:19:48 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*na_strchr(const char *source, int c)
{
	while (*source)
	{
		if (*source == (unsigned char)c)
			return ((char *)source);
		source++;
	}
	return ((char *)source);
}

static int	memry_alloc(int fd)
{
	char	*str;

	if (g_memry[fd] == NULL)
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
		return (0);
	if (str == NULL)
		return (1);
	*str = '\0';
	g_memry[fd] = str;
	return (0);
}

static char	*rescopy(t_mem lst, char **oldres)
{
	char	*joint;

	joint = na_strchr(lst.pull, '\n');
	if (*joint)
		lst.pull[joint - lst.pull + 1] = '\0';
	joint = ft_strjoin(*oldres, lst.pull);
	free(*oldres);
	return (joint);
}

char	*get_next_line(int fd)
{
	t_mem		lst;

	lst.result = malloc(sizeof(char));
	*lst.result = '\0';
	lst.read_len = BUFFER_SIZE;
	while (lst.read_len && 0 <= fd && fd < FD_MAX && (memry_alloc(fd) == 0))
	{
		ft_bzero(lst.pull, BUFFER_SIZE + 1);
		if (*g_memry[fd] == '\0')
			lst.read_len = read(fd, lst.pull, BUFFER_SIZE);
		else
			ft_strlcpy(lst.pull, g_memry[fd] + 1, ft_strlen(g_memry[fd]) + 1);
		if (lst.read_len < 0 || lst.result == NULL)
			break ;
		ft_strlcpy(g_memry[fd], na_strchr(lst.pull, '\n'), lst.read_len + 1);
		lst.result = rescopy(lst, &(lst.result));
		if (*g_memry[fd] == '\n' || (*lst.result && lst.read_len == 0))
			return (lst.result);
	}
	if (lst.result)
		free(lst.result);
	return (NULL);
}
