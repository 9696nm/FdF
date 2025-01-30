/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:17 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/30 12:57:22 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	window_close(int keycode, t_vars *vars)
{
	ft_putstr_fd("window close\n", STDOUT_FILENO);
	mlx_destroy_image(vars->mlx, vars->idata.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
