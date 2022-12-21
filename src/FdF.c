/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/21 12:02:06 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	ft_init_def(t_data *def)
{
	def->scale = 20;
	def->z_scale = 5;
	def->angle = 0.523599;
	def->distance_x = (WINDOW_WIDTH / 3);
	def->distance_y = (WINDOW_HEIGHT / 3);
	def->isometric = 1;
	return ;
}

int	ft_keyimg(int key)
{
	return (key == Z_MINUS || key == Z_PLUS);
}

void	ft_action(int keysym, t_data *data)
{
	if (keysym == Z_PLUS)
		data->z_scale += 1;
	if (keysym == Z_MINUS)
		data->z_scale -= 1;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
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
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		ft_action(keysym, data);
		ft_mlxdraw(data, &data->img);
		printf("hello\n");
	}
	printf("%d\n", keysym);
	return (0);
}

int	windown_quit(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	exit (1);
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}


void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
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
/*
void	test_img(t_img *img)
{
	int x1;
	int	x2;
	int y1;
	int	y2;
	
	x1 = WINDOW_WIDTH / 2;
	x2 = WINDOW_HEIGHT / 2;
	y1 = WINDOW_HEIGHT / 2;
	y2 = 750;
	//ft_bresenham_algo(img, (t_bresen){x1, y1, 0, 0, 1, 1, 0});
	//x2 = x2 + cos(15) * 10;
	//y2 = y2 + sin(15) * 10;
	//printf("x = %d\n", x2);
	//printf("y = %d\n", y2);
	//ft_bresenham_algo(img, (t_bresen){x1, y1, x2, y2, 1, 1, 0});
}
*/
int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	//render_background(&data->img, RED_PIXEL);
	ft_mlxdraw(data, &data->img);
	//render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
//			100, 100, GREEN_PIXEL});
//	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	
	// ft_bresenham_algo(&data->img, (t_bresen){0, 0, WINDOW_WIDTH, 0, 1, 1, 0});
	// ft_bresenham_algo(&data->img, (t_bresen){1500, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1, 1, 0});
	// ft_bresenham_algo(&data->img, (t_bresen){WINDOW_WIDTH, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 1, 1, 0});
	// ft_bresenham_algo(&data->img, (t_bresen){0, 0, 0, WINDOW_HEIGHT, 1, 1, 0});
	
	//test_img(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	ft_init_def(&data);
	data.matrix = ft_matrix(open(av[1], O_RDONLY), &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
								"fdf");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	/* HOOKS */
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, LeaveWindowMask, &windown_quit, &data);

	mlx_loop(data.mlx_ptr);

	/* Exit the loop if no window, and exe this*/
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free (data.mlx_ptr);
	exit(0);
}
//Prendre la taille de la fentre et diviser avec le nombre le carre pour avoir la taille des carres.
