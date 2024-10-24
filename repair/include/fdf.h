/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:53:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/29 11:57:19 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef enum	e_size
{
	SIZE_X = 1280,
	SIZE_Y = 720
}	t_size;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_idata;

typedef struct	s_point
{
	int	x;
	int	y;
	int	depth;
}	t_point;

typedef struct	s_axis
{
	double	x;
	double	y;
	double	z;
}	t_axis;

int	*ft_split_toi(char const *src, char c);

#endif
