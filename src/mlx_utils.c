/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:11:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/22 14:13:32 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	ft_keyimg(int key)
{
	return (key == Z_MINUS || key == Z_PLUS || key == ZOOM || \
	key == DEZOOM || key == LEFT || key == UP || key == DOWN || \
	key == RIGHT || key == SPACE || key == ROTATE_4 || key == ROTATE_6 \
	);
}

static int	ft_isometric(int isometric)
{
	if (isometric == 1)
		return (0);
	else
		return (1);
}

void	ft_action(int keysym, t_data *data)
{
	if (keysym == Z_PLUS)
		data->z_scale += 1;
	if (keysym == Z_MINUS)
		data->z_scale -= 1;
	if (keysym == ZOOM)
		data->scale += 1;
	if (keysym == DEZOOM)
		data->scale -= 1;
	if (keysym == LEFT)
		data->distance_x -= 50;
	if (keysym == RIGHT)
		data->distance_x += 50;
	if (keysym == UP)
		data->distance_y -= 50;
	if (keysym == DOWN)
		data->distance_y += 50;
	if (keysym == SPACE)
		data->isometric = ft_isometric(data->isometric);
	if (keysym == ROTATE_4)
		data->angle += 0.05;
	if (keysym == ROTATE_6)
		data->angle -= 0.05;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_ESCAPE)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(1);
	}
	if (keysym == ESC)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit (1);
	}
	if (ft_keyimg(keysym))
	{
		ft_action(keysym, data);
		ft_mlxdraw(data, &data->img);
	}
	return (0);
}

int	windown_quit(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	exit (1);
}
