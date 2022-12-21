/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linealgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:04:28 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/21 14:16:31 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static double	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void	ft_bresenham_algo(t_matrix a, t_matrix b, t_img *img, t_data *data)
{
	double	step_x;
	double	step_y;
	double	max;
	int		color;

	ft_setparam(&a, &b, data);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0x820f9f : 0x4b97f8;
	color = (b.z != a.z) ? 0xc1a61f : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		img_pix_put(img, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > WINDOW_WIDTH || a.y > WINDOW_HEIGHT || a.y < 0 || a.x < 0)
			break ;
	}
}
