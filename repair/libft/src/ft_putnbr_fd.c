/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:29:31 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:21:35 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	int	sing;

	sing = 1;
	if (-1 < nbr * sing)
		sing = -1;
	else
		ft_putchar_fd('-', fd);
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
