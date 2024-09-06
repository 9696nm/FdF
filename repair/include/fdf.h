/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:53:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/07 02:08:10 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"

typedef enum	e_size
{
	SIZE_X = 640,
	SIZE_Y = 360
}	t_size;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

#endif
