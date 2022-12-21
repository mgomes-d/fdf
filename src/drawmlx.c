/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:48:24 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/21 14:22:46 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	zoom(t_matrix *a, t_matrix *b, t_data *def)
{
	a->x *= def->scale;
	a->y *= def->scale;
	b->x *= def->scale;
	b->y *= def->scale;
	a->z *= def->z_scale;
	b->z *= def->z_scale;
}

static void	isometric(t_matrix *dot, double angle)
{
	double	x;

	x = dot->x;
	dot->x = roundf((dot->x - dot->y) * cos(angle));
	dot->y = roundf((x + dot->y) * sin(angle) - dot->z);
}

void	ft_setparam(t_matrix *a, t_matrix *b, t_data *def)
{
	zoom(a, b, def);
	if (def->isometric)
	{
		isometric(a, def->angle);
		isometric(b, def->angle);
	}
	a->x += def->distance_x;
	a->y += def->distance_y;
	b->x += def->distance_x;
	b->y += def->distance_y;
}

void	ft_mlxdraw(t_data *data, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	ft_bzero(img->addr, WINDOW_HEIGHT * WINDOW_WIDTH * sizeof(int));
	while (y < data->line)
	{
		x = 0;
		while (x < data->row[y])
		{
			if (y + 1 < data->line)
				ft_bresenham_algo(data->matrix[y][x], \
						data->matrix[y + 1][x], img, data);
			if (x + 1 < data->row[y])
				ft_bresenham_algo(data->matrix[y][x], \
						data->matrix[y][x + 1], img, data);
			x++;
		}
		y++;
	}
	return ;
}
