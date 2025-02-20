/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:53:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/20 20:06:01 by hana/hmori       ###   ########.fr       */
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

# include "q_rsqrt.h"
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define MOUSE_SENSITIVITY 0.005
# define WHEEL_SPPED 2
# define Z_ELASTICITY 0.1

typedef enum e_displaysize
{
	WIDTH = 1920,
	HEIGHT = 1080
}	t_dsize;

typedef enum e_glaphic_flag_name
{
	RE_GRAPHIC,
	MOUSE_PRESS
}	t_gfname;

typedef enum e_defalt_value
{
	DEF_ZOOM = 20,
	DEF_VIEW_X = 1,
	DEF_VIEW_Y = 1,
	DEF_VIEW_Z = 1,
	DEF_VIEW_AXIS = -30
}	t_defval;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_idata;

typedef struct s_vecter3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_quaternion
{
	float	w;
	t_vec3	v;
}	t_quater;

typedef struct s_array_offset
{
	float	x;
	float	y;
	float	z;
	float	z_elast;
}	t_arrof;

typedef struct s_parameter
{
	int		zoom;
}	t_param;

typedef struct s_mouse_coord
{
	int	press_x;
	int	press_y;
}	t_mcrd;

typedef struct s_glaphic_flag
{
	uint8_t	fl;
}	t_gflag;

typedef struct s_vecter_array
{
	int	**arr;
	int	width;
	int	length;
}	t_varr;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_idata		idata;
	t_dsize		dsize;
	t_varr		varr;
	t_quater	qv;
	t_quater	rqv;
	t_arrof		arrof;
	t_mcrd		mcrd;
	t_param		param;
	t_gflag		gflag;
}	t_vars;

// main
void		mlx(char *name, int **array);

// graphic unit
int			render_frame(t_vars *vars);
void		parameter_init(t_vars *vars);

// hook
int			mouse_move(int x, int y, t_vars *vars);
int			mouse_press(int button, int x, int y, t_vars *vars);
int			mouse_release(int button, int x, int y, t_vars *vars);
int			key_press(int keycode, t_vars *vars);
int			window_destroy(t_vars *vars);

// other unit
t_varr		crdarr_init(int **array);
t_arrof		arr_off_init(int **mat_arr);
t_quater	arr_off_set(int mx, int my, int mz, t_arrof arrof);
t_arrof		crd_off_move(t_quater rqv, t_arrof set, t_vec3 move);
t_vec3		crd_off_set(t_vec3 v, t_param param);

// quaternion action
t_quater	quater_normalize(t_quater q);
t_quater	quater_multiply(t_quater q1, t_quater q2);
t_quater	quater_conjugate(t_quater q);
t_quater	quater_rotate(t_quater qv, t_quater q);
t_quater	quater_axis_angle(float x, float y, float z, float angle);

#endif
