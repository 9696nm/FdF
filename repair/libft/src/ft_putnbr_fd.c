/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:29:31 by hmori             #+#    #+#             */
/*   Updated: 2024/09/06 12:56:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	int	sing;

	sing = 1;
	if (-1 < nbr * sing)
		sing = -1;
	else
		ft_putchar_fd('-', 1);
	if (nbr * sing < -9)
		ft_putnbr_fd(nbr * sing / -10, fd);
	ft_putchar_fd((nbr * sing % 10) * -1 + '0', fd);
}

// int	main(void)
// {
// 	int	n = INT_MIN;

// 	ft_putnbr_fd(n, 0);
// 	return (0);
// }
