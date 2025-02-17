/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:19:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/17 12:27:13 by hana/hmori       ###   ########.fr       */
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
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n",
			STDERR_FILENO);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("No file ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (1);
	}
	array = assig_arr(fd, 0, 0);
	close(fd);
	if (array == NULL)
		return (0);
	mlx(*argv, array);
	double_free(array);
	return (0);
}
