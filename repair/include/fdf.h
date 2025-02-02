/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:53:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/28 15:34:33 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <X11/X.h>
// # include <X11/keysym.h>
# include "mlx.h"

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# include <stdio.h> //!

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_idata;

typedef enum e_displaysize
{
	width = 1280,
	height = 720
}	t_dsize;

// typedef struct s_displaysize
// {
// 	unsigned int	width;
// 	unsigned int	height;
// }	t_dsize;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_idata	idata;
	// t_dsize	dsize;
}	t_vars;

typedef struct s_axis_float
{
	float	ax;
	float	ay;
	float	az;
}	t_axisf;

typedef struct s_vector_float
{
	float	x;
	float	y;
	float	z;
}	t_vectorf;

void	mlx(int **array);

// t_dsize	displaysize_init(t_xvar *xvar);
int		window_close(int keycode, t_vars *vars);

float	rotate_x(float x, float y, float theta);
float	rotate_y(float x, float y, float theta);

#endif
