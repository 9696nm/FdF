/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:33:04 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/30 23:33:23 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line(t_idata *idata, t_coord endp1, t_coord endp2, int thickness)
{
	int steps;
	float dx = endp2.crd_x - endp1.crd_x;
	float dy = endp2.crd_y - endp1.crd_y;

	// 変化量の大きい方をステップ数とする
	steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

	// 各ステップの増分を計算
	float x_inc = dx / steps;
	float y_inc = dy / steps;

	float x = endp1.crd_x, y = endp1.crd_y;

	// 描画
	for (int i = 0; i <= steps; i++) {
		my_mlx_pixel_put(idata, roundf(x), roundf(y), 0xFFFFFFFF); // 画像描画 (整数座標に変換)
		x += x_inc;
		y += y_inc;
	}
}
