/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:53:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/13 21:38:27 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include "mlx.h"
// # include "mlx_int.h"

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# include <stdio.h> //!

typedef enum e_displaysize
{
	WIDTH = 1920,
	HEIGHT = 1080
	// WIDTH = 1280,
	// HEIGHT = 720
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

typedef struct s_quaternion
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quater;

typedef struct s_translation
{
	float	x;
	float	y;
	float	z;
	float	zoom;
}	t_tarns;

typedef struct s_mouse_coord
{
	int	press_x;
	int	press_y;
}	t_mcoord;

typedef enum e_glaphic_flag_name
{
	GLAPH_ON = 1,
	GLAPH_OFF = 0,
	MOUSE_PRESS_ON = 1,
	MOUSE_PRESS_OFF = 0
}	t_gfname;

typedef struct s_glaphic_flag
{
	int	refresh;
	int	mouse_press;
}	t_gflag;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_idata		idata;
	t_dsize		dsize;
	int			**mat_arr;
	t_quater	qv;
	t_tarns		set;
	t_mcoord	mcrd;
	t_gflag		gflag;
}	t_vars;

typedef struct s_coord
{
	float	crd_x;
	float	crd_y;
	float	depth;
}	t_coord;

// main
void		mlx(char *name, int **array);

// mlx unit
void		my_mlx_pixel_put(t_idata *img, int x, int y, int color);
void		put_line(t_idata *idata, t_coord q1, t_coord q2);
// t_dsize		displaysize_init(t_xvar *xvar);

// hook
int			mouse_move(int x, int y, t_vars *vars);
int			mouse_press(int button, int x, int y, t_vars *vars);
int			mouse_release(int button, int x, int y, t_vars *vars);
int			key_press(int keycode, t_vars *vars);
int			window_destroy(t_vars *vars);

// other unit
t_tarns		set_trans(int **mat_arr);
t_coord		set_coord(int crd_x, int crd_y, int depth);
t_quater	set_quat(float w, float x, float y, float z);
t_tarns		reverse_quater(t_quater qv, t_quater p, t_tarns set);
// t_quater	rotate_vector_mouse(t_vars *vars, int x, int y);

// quaternion action
t_quater	quater_normalize(t_quater q);
t_quater	quater_multiply(t_quater q1, t_quater q2);
t_quater	quater_conjugate(t_quater q);
t_quater	quater_rotate(t_quater qv, t_quater q);
t_quater	quaternion_axis_angle(float x, float y, float z, float angle);

#endif
