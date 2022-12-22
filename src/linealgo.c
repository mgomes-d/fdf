/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linealgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:04:28 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/22 11:44:37 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static double	fmodule(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

static int	ft_color(double a, double b)
{
	int	color;

	if (b || a)
		color = 0x820f9f;
	else
		color = 0x4b97f8;
	if (b != a)
		color = 0xc1a61f;
	return (color);
}

static int	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
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
	max = ft_max(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = ft_color(a.z, b.z);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		img_pix_put(img, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > WINDOW_WIDTH || a.y > WINDOW_HEIGHT || a.y < 0 || a.x < 0)
			break ;
	}
}
