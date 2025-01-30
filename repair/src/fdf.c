/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:19:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/28 18:02:07 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_idata *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || width <= x || y < 0 || height <= y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// static t_point	*set_axis(int **array, t_axis axis)
// {
// 	;
// }

// static void	set_pixel(t_axis axis)
// {

// }

static void	mlx(int **array)
{
	t_vars	vars;
	t_axisf	axis;

	axis.x = 0;
	axis.y = 0;
	axis.z = 0;

	int zoom = 50;
	int	or_x = 5;
	int	or_y = 5;
	float	or_z = 0.3F;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "fdf");
	vars.idata.img = mlx_new_image(vars.mlx, width, height);
	vars.idata.addr = mlx_get_data_addr(vars.idata.img, &vars.idata.bits_per_pixel, &vars.idata.size_line,
			&vars.idata.endian);
	for (int ly=0; array[ly]; ly++)
		for (int lx=0; lx<array[ly][0]; lx++)
		{
			my_mlx_pixel_put(&vars.idata, (int)(rotate_x(rotate_x(lx-or_x, ly-or_y, axis.z), array[ly][lx+1]*or_z, axis.y)*zoom+width/2),
				(int)(rotate_x(rotate_y(lx-or_x, ly-or_y, axis.z), array[ly][lx+1]*or_z, axis.x)*zoom+height/2), 0xFFFFFFFF);//+(ly*20<<24)
		}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.idata.img, 0, 0);
	mlx_hook(vars.win, KeyPress, KeyPressMask, window_close, &vars);
	mlx_loop(vars.mlx);
}

static int	**assig_arr(int fd, int length) //ft_split_toi recursive function version
{
	char	*ret;
	int		*sp_arr;
	int		**result;

	ret = get_next_line(fd);
	if (ret == NULL)
		return (ft_calloc(sizeof(int *), length + 1));
	if (ft_strchr(ret, '\n'))
		ret[ft_strchr(ret, '\n') - ret] = '\0';
	sp_arr = ft_split_toi(ret, ' ');
	free(ret);
	if (sp_arr == NULL)
		return (NULL);
	result = assig_arr(fd, length + 1);
	if (result)
		result[length] = sp_arr;
	else
		free(sp_arr);
	return (result);
}

static void	double_free(int **array)
{
	int	**mem;

	mem = array;
	while (*mem)
		free(*mem++);
	free(array);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	**array;

	if (argc != 2)
	{
		ft_putstr_fd("format error -> ./fdf [path].fdf\n", STDOUT_FILENO);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	array = assig_arr(fd, 0);
	close(fd);
	mlx(array);
	double_free(array);
	return (0);
}

	// vars.dsize = displaysize_init(vars.mlx);

	// int tfd = open("dtest", O_WRONLY | O_TRUNC);
	// for (int y=0; array[y]; y++)
	// {
	// 	for (int x=0; x<array[y][0]; x++)
	// 	{
	// 		ft_putnbr_fd(array[y][x + 1], tfd);
	// 		ft_putchar_fd(' ', tfd);
	// 	}
	// 	ft_putchar_fd('\n', tfd);
	// }
	// close(tfd);

// static int	**assig_arr(int fd, int length) //ft_split->atoi recursive function version
// {
// 	int		width;
// 	int		*element;
// 	int		**array;
// 	char	*ret;
// 	char	**sp_arr;

// 	ret = get_next_line(fd);
// 	if (ret == NULL)
// 		return (len_alloc(length));
// 	sp_arr = ft_split(ret, ' ');
// 	free(ret);
// 	width = 0;
// 	printf("%d:%s\n", length, sp_arr[width]);
// 	while (ft_strchr(sp_arr[width], '\n') == NULL)
// 		width++;
// 	element = malloc(sizeof(int) * (width + 1));
// 	element[0] = width;
// 	while (0 < width--)
// 		element[width + 1] = ft_atoi(sp_arr[width]);
// 	double_free(sp_arr);
// 	array = assig_arr(fd, length + 1);
// 	array[length] = element;
// 	return (array);
// }

// int	main(int argc, char *argv[])
// {
// 	int	fd;
// 	int	**array;

// 	if (argc != 2)
// 	{
// 		ft_putstr_fd("format error -> ./fdf [path].fdf\n", STDOUT_FILENO);
// 		return (0);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	array = assig_arr(fd, 0);
// 	close(fd);
// 	mlx(array);
// 	int	len = 0;
// 	while (array[len])
// 		free(array[len++]);
// 	free(array);
// 	return (0);
// }
