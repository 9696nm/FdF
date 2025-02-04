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

// static t_coord	*set_lane(char **sp_arr, int length, int width)
// {
// 	t_coord	*lane;

// 	if (sp_arr == NULL)
// 		return (NULL);
// 	if (*sp_arr == NULL || **sp_arr == '\n')
// 		return (ft_calloc(sizeof(t_coord *), (width + 1)));
// 	lane = set_lane(sp_arr + 1, length, width + 1);
// 	lane[width].x = width;
// 	lane[width].y = length;
// 	lane[width].z = ft_atoi(*sp_arr);
// }

static int	**assig_arr(int fd, int length, int width_size) //ft_split_toi recursive function version
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
	if (width_size == 0 || *sp_arr == width_size)
		result = assig_arr(fd, length + 1, *sp_arr);
	else
		ft_putstr_fd("Found wrong line length. Exiting.\n", STDOUT_FILENO);
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
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n", STDOUT_FILENO);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("No file ", STDOUT_FILENO);
		ft_putstr_fd(argv[1], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (0);
	}
	array = assig_arr(fd, 0, 0);
	close(fd);
	if (array == NULL)
		return (0);
	mlx(*argv, array);
	double_free(array);
	return (0);
}

// static int	**assig_arr(int fd, int length) //ft_split_toi recursive function version
// {
// 	char	*ret;
// 	int		*sp_arr;
// 	int		**result;

// 	ret = get_next_line(fd);
// 	if (ret == NULL)
// 		return (ft_calloc(sizeof(int *), length + 1));
// 	if (ft_strchr(ret, '\n'))
// 		ret[ft_strchr(ret, '\n') - ret] = '\0';
// 	sp_arr = ft_split_toi(ret, ' ');
// 	free(ret);
// 	if (sp_arr == NULL)
// 		return (NULL);
// 	result = assig_arr(fd, length + 1);
// 	if (result)
// 		result[length] = sp_arr;
// 	else
// 		free(sp_arr);
// 	return (result);
// }

// static void	double_free(int **array)
// {
// 	int	**mem;

// 	mem = array;
// 	while (*mem)
// 		free(*mem++);
// 	free(array);
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
// 	double_free(array);
// 	return (0);
// }

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
