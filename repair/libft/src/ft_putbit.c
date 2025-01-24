/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:32:15 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/23 23:33:23 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbit(unsigned long int num, uint8_t bytesize)
{
	bytesize *= 8;
	while (bytesize--)
		ft_putchar_fd((num >> bytesize & 0b1) + '0', STDOUT_FILENO);
}
