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

typedef enum e_displaysize
{
	WIDTH = 1280,
	HEIGHT = 720
}	t_dsize;

// typedef struct s_displaysize
// {
// 	unsigned int	width;
// 	unsigned int	height;
// }	t_dsize;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_idata;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_idata	idata;
	// t_dsize	dsize;
}	t_vars;

typedef struct s_translation
{
	int	set_x;
	int	set_y;
	int	set_z;
}	t_tarns;

typedef struct s_quaternion_vecter
{
	int		vec_x;
	int		vec_y;
	int		vec_z;
	float	theta;
}	t_quatev;

typedef struct s_euler_angle_float
{
	float	ang_x;
	float	ang_y;
	float	ang_z;
}	t_eanglef;

typedef struct s_coord
{
	float	crd_x;
	float	crd_y;
	float	depth;
}	t_coord;

void	mlx(char *name, int **array);

void	my_mlx_pixel_put(t_idata *img, int x, int y, int color);
// t_dsize	displaysize_init(t_xvar *xvar);
int		window_close(int keycode, t_vars *vars);

float	rotate_x(float x, float y, float theta);
float	rotate_y(float x, float y, float theta);
t_coord	rotate_matrix(float vec_x, float vec_y, float vec_z, t_eanglef ang);

void	put_line(t_idata *idata, t_coord endp1, t_coord endp2, int thickness);

#endif
