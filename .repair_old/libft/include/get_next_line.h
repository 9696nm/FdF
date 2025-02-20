/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:33:31 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 12:12:06 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/select.h>

# include "libft.h"

# ifndef FD_MAX
#  define FD_MAX FD_SETSIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# if BUFFER_SIZE > 65536
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 65536
# endif

typedef struct s_mem
{
	ssize_t	read_len;
	char	*result;
	char	pull[BUFFER_SIZE + 1];
}	t_mem;

static char	*g_memry[FD_MAX];

char	*get_next_line(int fd);
// char	*get_next_line(int fd, char	*memry[FD_MAX]);

#endif