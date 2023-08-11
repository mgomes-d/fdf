/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/11 11:30:48 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	ft_init_def(t_data *def)
{
	def->scale = 20;
	def->z_scale = 5;
	def->angle = 0.523599;
	def->distance_x = (WINDOW_WIDTH / 3) + (def->line / 2);
	def->distance_y = (WINDOW_HEIGHT / 3) + (def->line / 2);
	def->isometric = 1;
	return ;
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x <= WINDOW_WIDTH && x >= 0 && y <= WINDOW_HEIGHT && y >= 0)
	{
		i = img->bpp - 8;
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

static int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	ft_mlxdraw(data, &data->img);
	mlx_put_image_to_window(data->mlx_ptr, \
			data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

static int	ft_mlx_data(t_data *data, char **av)
{
	ft_init_def(data);
	(void)av;
	data->matrix = ft_matrix(open(av[1], O_RDONLY), data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
			"fdf");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	ft_mlx_data(&data, av);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KEYPRESS, (1L << 0), &handle_keypress, &data);
	mlx_hook(data.win_ptr, DESTROYNOTIFY, (1L << 5), &windown_quit, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free (data.mlx_ptr);
	exit(0);
}
