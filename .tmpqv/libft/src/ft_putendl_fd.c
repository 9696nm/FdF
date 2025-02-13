/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:06:12 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:21:31 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}

// int	main(void)
// {
// 	int		fd = 1;
// 	char	*text = "abcd012";

// 	ft_putendl_fd(text, fd);
// 	return (0);
// }
