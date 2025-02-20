/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:19:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/20 20:05:38 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	**assig_arr(int fd, int length, int width_size)
{
	char	*ret;
	int		*sp_arr;
	int		**result;

	result = NULL;
	ret = get_next_line(fd);
	if (ret == NULL)
		return (ft_calloc(sizeof(int *), length + 1));
	if (ft_strchr(ret, '\n'))
		ret[ft_strchr(ret, '\n') - ret] = '\0';
	sp_arr = ft_split_toi(ret, ' ');
	free(ret);
	if (sp_arr == NULL)
		return (NULL);
	if (*sp_arr == 0)
		ft_putstr_fd("No data found.\n", STDERR_FILENO);
	else if (width_size == 0 || *sp_arr == width_size)
		result = assig_arr(fd, length + 1, *sp_arr);
	else
		ft_putstr_fd("Found wrong line length. Exiting.\n", STDERR_FILENO);
	if (result)
		result[length] = sp_arr;
	else
		free(sp_arr);
	return (result);
}

void	mlx(char *name, int **mat_arr)
{
	t_vars	vars;

	vars.varr = crdarr_init(mat_arr);
	parameter_init(&vars);
	vars.arrof = arr_off_init(vars.varr.arr);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, name);
	vars.idata.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.idata.addr = mlx_get_data_addr(vars.idata.img,
			&vars.idata.bits_per_pixel,
			&vars.idata.size_line, &vars.idata.endian);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_press, &vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, mouse_press, &vars);
	mlx_hook(vars.win, ButtonRelease, ButtonReleaseMask, mouse_release, &vars);
	mlx_hook(vars.win, MotionNotify, PointerMotionMask, mouse_move, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask,
		window_destroy, &vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}

static void	double_free(int **array)
{
	int	**mem;

	mem = array;
	while (*mem)
		free(*mem++);
	free(array);
}

static int	err_turn(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	**array;

	if (argc != 2)
		return (err_turn("Usage : ./fdf <filename> [ case_size z_size ]\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("No file ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		return (err_turn("\n"));
	}
	array = assig_arr(fd, 0, 0);
	close(fd);
	if (array == NULL)
		return (1);
	if (array[0] == NULL)
	{
		free(array);
		return (err_turn("No data found.\n"));
	}
	mlx(*argv, array);
	double_free(array);
	return (0);
}
