/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rsqrt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:26:34 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/02/13 20:35:25 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Q_RSQRT_H
# define Q_RSQRT_H

# include <fcntl.h>

typedef union u_cast
{
	long int	li;
	float		f;
}	t_cast;

float	q_rsqrt(float number);

#endif
